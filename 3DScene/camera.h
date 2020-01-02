//#include "import.h"
#include "vector3.h"


class Camera {
public:
	Point3 eye;
	Vector3 u, v, n;
	double viewAngle, aspect, nearDist, farDist; // view volume shape

public:
	Camera(); // default constructor

	void setCamera(Point3 eye, Point3 look, Vector3 up); // like gluLookAt()
	void set(float eyex, float eyey, float eyez,
		float lookx, float looky, float lookz,
		float upx, float upy, float upz);

	void setModelViewMatrix(); // tell OpenGL where the camera is

	Point3 getEye() { return eye; }

	void roll(float angle); // roll it
	void pitch(float angle); // increase pitch
	void yaw(float angle); // yaw it
	void slide(float delU, float delV, float delN); // slide it
	void setShape(float vAng, float asp, float nearD, float farD)
	{
		viewAngle = vAng;
		aspect = asp;
		nearDist = nearD;
		farDist = farD;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(vAng, asp, nearD, farD);
	}
};
Camera::Camera()
{
	viewAngle = aspect = nearDist = farDist = 0;
} // default constructor


// -------------set---------------
// inputs: Eye--coords for the Eye, 
//         look--where it is looking 
//         up--the up vector
// outputs: none
// purpose: sets the n,u,v vectors (internal use for camera) and sets Model Matrix
// source: FS Hill p. 367

void Camera::setCamera(Point3 Eye, Point3 look, Vector3 up)
{	// create a modelview matrix and send it to OpenGL
	eye.set(Eye); // store the given eye position
	n.set(eye.x - look.x, eye.y - look.y, eye.z - look.z); // make n
	u.set(up.cross(n)); // make u = up X n
	n.normalize(); u.normalize(); // make them unit length
	v.set(n.cross(u));  // make v =  n X u
	setModelViewMatrix(); // tell OpenGL 
}

void Camera::set(float eyex, float eyey, float eyez,
	float lookx, float looky, float lookz,
	float upx, float upy, float upz)
{	// create a modelview matrix and send it to OpenGL
	Point3 Eye(eyex, eyey, eyez);
	Point3 look(lookx, looky, lookz);
	Vector3 up(upx, upy, upz);

	eye.set(Eye); // store the given eye position
	n.set(eye.x - look.x, eye.y - look.y, eye.z - look.z); // make n
	u.set(up.cross(n)); // make u = up X n
	n.normalize(); u.normalize(); // make them unit length
	v.set(n.cross(u));  // make v =  n X u
	setModelViewMatrix(); // tell OpenGL 
}


// -------------setModelViewMatrix---------------
// inputs: none
// outputs: none
// purpose: uses n,u,v to set up model view matrix
// source: FS Hill p. 367
void Camera::setModelViewMatrix(void)
{ // load modelview matrix with existing camera values
	float m[16];
	Vector3 eVec(eye.x, eye.y, eye.z); // a vector version of eye 
	m[0] = u.dx; m[4] = u.dy; m[8] = u.dz;  m[12] = -eVec.dot(u);
	m[1] = v.dx; m[5] = v.dy; m[9] = v.dz;  m[13] = -eVec.dot(v);
	m[2] = n.dx; m[6] = n.dy; m[10] = n.dz;  m[14] = -eVec.dot(n);
	m[3] = 0;   m[7] = 0;   m[11] = 0;    m[15] = 1.0;
	glMatrixMode(GL_MODELVIEW);
	//glPushMatrix();
	glLoadMatrixf(m); // load OpenGL's modelview matrix
	//glPopMatrix();
}

// -------------slide---------------
// inputs: delU, delV, delN -- gives quantity of slide along each vector
// outputs: none
// purpose: combines three possible slides into one function, sliding along
//          u,v,n vectors according to numbers in delU, delV, delN
// source: FS Hill p. 368
void Camera::slide(float delU, float delV, float delN)
{
	eye.x += delU * u.dx + delV * v.dx + delN * n.dx;
	eye.y += delU * u.dy + delV * v.dy + delN * n.dy;
	eye.z += delU * u.dz + delV * v.dz + delN * n.dz;
	setModelViewMatrix();		// inform OpenGL

	//gluLookAt(eye.x,eye.y,eye.z,0,0.25,0,0,1,0);
}

// -------------roll---------------
// inputs: angle -- gives quantity of roll
// outputs: none
// purpose: roll around according to given angle
// source: FS Hill p. 369
void Camera::roll(float angle)
{
	float cs = cos(3.14159265 / 180 * angle);
	float sn = sin(3.14159265 / 180 * angle);
	Vector3 t = u; 		// remember old u

	//cout<< "humera1";  
	u.set(cs*t + sn * v);
	v.set(cs*v - sn * u);

	//  u.set(cs*t.x - sn*v.x, cs*t.y - sn*v.y, cs*t.z - sn*v.z); 
	//v.set(sn*t.x + cs*v.x, sn*t.y + cs*v.y, sn*t.z + cs*v.z);

	setModelViewMatrix();		// inform OpenGL
}

// -------------pitch---------------
// inputs: angle -- gives quantity of pitch
// outputs: none
// purpose: pitch according to given angle
// source: FS Hill p. 369
void Camera::pitch(float angle) // increase pitch
{
	float cs = cos(3.14159265 / 180 * angle);
	float sn = sin(3.14159265 / 180 * angle);
	Vector3 n1 = cs * n + sn * v;
	Vector3 v1 = cs * v - sn * n;

	n.set(n1);
	v.set(v1);

	setModelViewMatrix();		// inform OpenGL
}

// -------------yaw---------------
// inputs: angle -- gives quantity of yaw
// outputs: none
// purpose: yaw according to given angle
// source: FS Hill p. 369
void Camera::yaw(float angle) // increase pitch
{
	float cs = cos(3.14159265 / 180 * angle);
	float sn = sin(3.14159265 / 180 * angle);
	Vector3 n1 = cs * n + sn * u;
	Vector3 u1 = (cs)*u - sn * n;

	u.set(u1);
	n.set(n1);
	setModelViewMatrix();		// inform OpenGL
}

//void Camera::setShape(float vAng, float asp, float nearD, float farD);

