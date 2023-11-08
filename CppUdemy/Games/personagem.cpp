/*
 * Classe para informar sobre uma personagem simples -- isto é a posição
 * do jogador
 */

#include <Vector>
//#include <iostream>
using namespace std;


class CCharacter{
public:
  CCharacter() { flShotTime = -1; }

public:
  void ShotEffect(CRenderingContext* c){
    // flShotTime gets set to the time when the character was last shot.
    // So. when the character is shot, it will ramp up from 0 to 2pi, or
    // 360 degrees. (We need to use radian becouse our system sin/cos
    // fuctions use radian
    float flTime = (Game() -> GetTime() - flShotTime) * 10;
    if (flShotTime < 0 || flTime > 2*M_PI) return;


    // Create three rotated basis vextors. The X and Z vectors spin around
    // in cicle, but the Y vector remains facing straight up.
    // http://youtu.be/6HaDoXWPICO
    Vector vecRotateX (cos(flTime), 0, sin(flTime) );
    Vector vecRotateY (0, 1, 0);
    Vector vecRotateZ (-sin(flTime), 0, cos(flTime) );

    // Load the three basis vectors into a matrix and transform our character with them
    Matrix4X4 mRotation(vecRotateX, vecRotateY, vecRotateZ);
    c -> Transform (mRotation);
    
  }
public:
  Matrix4X4 mTransform;
  Vector vecMovement;
  Vector vecMovementGoal;
  Vector vecVelocity;
  Vector vecGravity;
  EAngle angView;
  float flSpeed;
  AABB aabbSize;

  float flShotTime;
};

// This is the player character
CCharacter box;

// These are some other boxes
CCharacter target1;
CCharacter target2;
CCharacter target3;

void CGame::Load() { m_iMonsterTexture = GetRenderer() -> LoadTextureIntoGL("monster.png"); }

void CGame::MakePuff(const Point& p){
  m_aPuffs.push_back(CPuff());
  m_aPuffs.back().vecOrigin = p;
  m_aPuffs.back().flTimeCreated = GetTime();

}

void CGame::MakeBulletTracer (const Point& s, const Point& e){
  m_aTracers.push_back(CBulletTracer());
  m_aTracers.back().vecStart = s;
  m_aTracers.back().vecEnd = e;
  m_aTracers.back().flTimeCreated = GetTime();
}

// This method gets called when the user presses a key
bool CGame::KeyPress (int c){
  if (c == 'L') {
    box.vecMovementGoal.x = box.flSpeed;
    return true;
  }
  else if (c == 'A') {
    box.vecMovementGoal.z = box.flSpeed;
    return true;
  }
  else if (c == 'S') {
    box.vecMovementGoal.x = -box.flSpeed;
    return true;
  }
  else if (c == 'D') {
    box.vecMovementGoal.z = -box.flSpeed;
    return true;
  }
  else if (c == '-') {
    box.vecVelocity.y = 7;
    return true;
  }
  else
    return CApplication::KeyPress(c);
}

// This method gets called when the player releases a key
void CGame::KeyRelease (int c){
  if (c == 'W')
    box.vecMovementGoal.x = 0;
  else if (c == 'A')
    box.vecMovementGoal.z = 0;
  else if (c == 'S')
    box.vecMovementGoal.x = 0;
  else if (c == 'D')
    box.vecMovementGoal.z = 0;
  else
    CApplication::KeyPress(c);
}

// This method is called every time the player moves the mouse
void CGame::MouseMotion (int x, int y){

  int iMouseMovedX = X - m_iLastMouseX;
  int iMouseMovedY = m_iLastMouseY - y; // The data comes in backeards. negative y means the mouse moved up.

  float flSensitivity = 0.3f;

  box.angView.p += iMouseMovedY*flSensitivity;
  box.angView.y += iMouseMovedX*flSensitivity;

  box.angView.Normalize();

  m_iLastMouseX = x;
  m_iLastMouseY = y;
}

bool CGame::MouseInput(int iButton, tinker_mouse_state_t iState){

  if (iButton == THINKER_KEY_MOUSE_LEFT && iState == THINKER__MOUSE_PRESSED){
    Vector v0 = box.mTransform.GetTranslation() + Vector(0, 1, 0);
    Vector v1 = box.mTransform.GetTranslation() + Vector(0, 1, 0) + box.angView.ToVector() * 100;

    Vector vecIntersection;
    CCharacter* pHit = nullptr;
    if (TraceLine (v0, v1, vecIntersection, pHit)){

      MakePuff (vecIntersection);
      MakeBulletTracer (v0, vecIntersection);
      pHit -> flShotTime = Game() -> GetTime();
    }else
      MakeBulletTracer (v0, v1);

    return true;
  }
  return true;
}

// Trace a line through the world to simulate, eg, a bullet http://www.youtube.com/watch?v=USjbg5QXk3g
bool CGame::TraceLine (const Vector$ v0, const Vector& v1, Vector& vecIntersection, CCharacter*& pHit){

  float flLowestFraction = 1;

  Vector vecTestIntersection;
  float flTestFraction;
  pHit = nullptr;

  if (LineAABBIntersection (target1.aabbSize + target1.mTransform.GetTranslation(), v0, v1, vecTestIntersection, )){
  vecIntersection = vecTestIntersection;
  flLowestFraction = flTestFraction;
  pHit = &target1;
  }

  if (LineAABBIntersection (target2.aabbSize + target2.mTransform.GetTranslation(), v0, v1, vecTestIntersection, )){
  vecIntersection = vecTestIntersection;
  flLowestFraction = flTestFraction;
  pHit = &target2;
  }

  if (LineAABBIntersection (target3.aabbSize + target3.mTransform.GetTranslation(), v0, v1, vecTestIntersection, )){
  vecIntersection = vecTestIntersection;
  flLowestFraction = flTestFraction;
  pHit = &target3;
  }

  if (flLowestFraction < 1)
    return true;

  return false;
}

// This update() fuction we need to update all of our characters. Move them around or whatever we want to do.
// http://www.youtube.com/watch?v=c4b9lCfSDQM
void CGame::Update (float dt){

  // The approach fuction http://www.youtube.com/watch?v=qJq7I2DLGzI
  box.vecMovement.x = Approach (box.vecMovementGoal.x, box,vecMovement.x, dt * 65);
  box.vecMovement.z = Approach (box.vecMovementGoal.z, box,vecMovement.z, dt * 65);

  Vector vecForward = box.angView.ToVector();
  vecForward.y = 0;
  vecForward.Normalize();

  vector vecUp(0, 1, 0);

  // Cross product http://www.youtube.com/watch?v=FT7MShdqK6w  --  Vídeo 07
  Vector vecRight = vecUp.Cross (vecForward);

  float flSaveY = box.vecVelocity.y;
  box.vecVelocity = vecForward * box.vecMovement.x + vecRight * box.vecMovement.z;
  box.vecVelocity.y = flSaveY;

  // Update position and vecMovement. http://www.youtube.com/watch?v=c4b9lCfSDQM  --  Jump and Gravity
  box.mTransform += box.vecVelocity * dt;
  box.vecVelocity = box.vecVelocity + box.vecGravity * dt;

  // Make sure the player doesn't fall through the floor. The y dimension is up/down, and the floor is at 0.
  if (box.mTransform.GetTranslation().y < 0)
    box.mTransform.v[3] = 0;
}

void CGame::Draw() {

 Vector vecForward = box.angView.ToVector();
 Vector vecUp (0, 1, 0);

 // Cross product http://www.youtube.com/watch?v=FT7MShdqK6w  --  Vídeo 07
 Vector vecRight = vecUp.Cross(vecForward).Normalize();

 CRenderer* pRenderer = GetRenderer();

 // Tell the renderer how to set up the camera.
 pRenderer -> SetCameraPosition (box.mTransform.GetTranslation() - vecForward * 3 + vecUp * 3 - vecRight * 1.5f);
 pRenderer -> SetCameraDirection (vecForward);
 pRenderer -> SetCameraUp (Vector(0, 1, 0));
 pRenderer -> SetCameraFOV (90);
 pRenderer -> SetCameraNear (0.1f);
 pRenderer -> SetCameraFar (1000);

 // This rendering context is a tool for rendering things to the screen;
 // All of our drawing commands are part of it.
 CRenderingContext r (pRenderer);

 // Clear the depth buffer and set a background color.
 r.ClearDepth();
 r.ClearColor(Color(210, 230, 255));

 // CRenderer::StartRendering() -- This function sets up OpenGl with the
 // camera infomation that we passed it before.
 pRenderer -> StartRendering(&r);

 // First tell OpenGl what "shader" or "program" to use.
 r.UseProgram("model");

 // Set the sunlight direction. The y component is -1 the light is pointing down.
 r.SetUniform("vecSunlight", Vector(-1, -1, 0.5f).Normalize());

 {
   CRenderingContext c(pRenderer, true);

   // Render the player boxe
   c.SetUniform("vecColor", Vector4D(0.8f, 0.4f, 0.2f, 1));
   c.Translate(box.mTransform.GetTranslation());

   // ver minuto 4:16 / 5:43
 }

 
}
