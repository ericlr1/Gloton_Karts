#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	Cylinder wheel;

	wheel.color = Blue;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);
		wheel.color = Gray;
		wheel.Render();
	}
	//MESH DEL KART 
	//Pieza 1 --------------------------------------------------------------------------------------------
	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());
	chassis.color = Purple;
	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();
	//Pieza 2 --------------------------------------------------------------------------------------------
	Cube chassis1(info.chassis1_size.x, info.chassis1_size.y, info.chassis1_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis1.transform);
	btQuaternion q1 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset1(info.chassis1_offset.x, info.chassis1_offset.y, info.chassis1_offset.z);
	offset1 = offset1.rotate(q1.getAxis(), q1.getAngle());
	chassis1.color = Green;
	chassis1.transform.M[12] += offset1.getX();
	chassis1.transform.M[13] += offset1.getY();
	chassis1.transform.M[14] += offset1.getZ();
	//Pieza 3 --------------------------------------------------------------------------------------------
	Cube chassis2(info.chassis2_size.x, info.chassis2_size.y, info.chassis2_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis2.transform);
	btQuaternion q2 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset2(info.chassis2_offset.x, info.chassis2_offset.y, info.chassis2_offset.z);
	offset2 = offset2.rotate(q2.getAxis(), q2.getAngle());
	chassis2.color = Dark_Green;
	chassis2.transform.M[12] += offset2.getX();
	chassis2.transform.M[13] += offset2.getY();
	chassis2.transform.M[14] += offset2.getZ();
	//Pieza 4 --------------------------------------------------------------------------------------------
	Cube chassis3(info.chassis3_size.x, info.chassis3_size.y, info.chassis3_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis3.transform);
	btQuaternion q3 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset3(info.chassis3_offset.x, info.chassis3_offset.y, info.chassis3_offset.z);
	offset3 = offset3.rotate(q3.getAxis(), q3.getAngle());
	chassis3.color = Dark_Green;
	chassis3.transform.M[12] += offset3.getX();
	chassis3.transform.M[13] += offset3.getY();
	chassis3.transform.M[14] += offset3.getZ();
	//Pieza 5 --------------------------------------------------------------------------------------------
	Cube chassis4(info.chassis4_size.x, info.chassis4_size.y, info.chassis4_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis4.transform);
	btQuaternion q4 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset4(info.chassis4_offset.x, info.chassis4_offset.y, info.chassis4_offset.z);
	offset4 = offset4.rotate(q4.getAxis(), q4.getAngle());
	chassis4.color = Gray;
	chassis4.transform.M[12] += offset4.getX();
	chassis4.transform.M[13] += offset4.getY();
	chassis4.transform.M[14] += offset4.getZ();
	vec3 u = { 1,0,0 };
	chassis4.transform.rotate(-40,u); //INTENTO DE ROTAR (PROBLEMA: ROTA EL OBJETO COMO SI FUESE UN UPDATE)
	//Pieza 6 --------------------------------------------------------------------------------------------
	Cube chassis5(info.chassis5_size.x, info.chassis5_size.y, info.chassis5_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis5.transform);
	btQuaternion q5 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset5(info.chassis5_offset.x, info.chassis5_offset.y, info.chassis5_offset.z);
	offset5 = offset5.rotate(q5.getAxis(), q5.getAngle());
	chassis5.color = Gray;
	chassis5.transform.M[12] += offset5.getX();
	chassis5.transform.M[13] += offset5.getY();
	chassis5.transform.M[14] += offset5.getZ();
	chassis5.transform.rotate(-40, u); //INTENTO DE ROTAR (PROBLEMA: ROTA EL OBJETO COMO SI FUESE UN UPDATE)
	//Pieza 7 --------------------------------------------------------------------------------------------
	Cube chassis6(info.chassis6_size.x, info.chassis6_size.y, info.chassis6_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis6.transform);
	btQuaternion q6 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset6(info.chassis6_offset.x, info.chassis6_offset.y, info.chassis6_offset.z);
	offset6 = offset6.rotate(q6.getAxis(), q6.getAngle());
	chassis6.color = Green;
	chassis6.transform.M[12] += offset6.getX();
	chassis6.transform.M[13] += offset6.getY();
	chassis6.transform.M[14] += offset6.getZ();
	//Pieza 8 --------------------------------------------------------------------------------------------
	Cube chassis7(info.chassis7_size.x, info.chassis7_size.y, info.chassis7_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis7.transform);
	btQuaternion q7 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset7(info.chassis7_offset.x, info.chassis7_offset.y, info.chassis7_offset.z);
	offset7 = offset7.rotate(q7.getAxis(), q7.getAngle());
	chassis7.color = Green;
	chassis7.transform.M[12] += offset7.getX();
	chassis7.transform.M[13] += offset7.getY();
	chassis7.transform.M[14] += offset7.getZ();
	//Pieza 9 --------------------------------------------------------------------------------------------
	Cube chassis8(info.chassis8_size.x, info.chassis8_size.y, info.chassis8_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis8.transform);
	btQuaternion q8 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset8(info.chassis8_offset.x, info.chassis8_offset.y, info.chassis8_offset.z);
	offset8 = offset8.rotate(q8.getAxis(), q8.getAngle());
	chassis8.color = Green;
	chassis8.transform.M[12] += offset8.getX();
	chassis8.transform.M[13] += offset8.getY();
	chassis8.transform.M[14] += offset8.getZ();
	chassis8.transform.rotate(60, u); //INTENTO DE ROTAR (PROBLEMA: ROTA EL OBJETO COMO SI FUESE UN UPDATE)
	//Pieza 10 --------------------------------------------------------------------------------------------
	Cube chassis9(info.chassis9_size.x, info.chassis9_size.y, info.chassis9_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis9.transform);
	btQuaternion q9 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset9(info.chassis9_offset.x, info.chassis9_offset.y, info.chassis9_offset.z);
	offset9 = offset9.rotate(q9.getAxis(), q9.getAngle());
	chassis9.color = Gray2;
	chassis9.transform.M[12] += offset9.getX();
	chassis9.transform.M[13] += offset9.getY();
	chassis9.transform.M[14] += offset9.getZ();
	chassis9.transform.rotate(75, u); //INTENTO DE ROTAR (PROBLEMA: ROTA EL OBJETO COMO SI FUESE UN UPDATE)
	//Pieza 11 --------------------------------------------------------------------------------------------
	Cube chassis10(info.chassis10_size.x, info.chassis10_size.y, info.chassis10_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis10.transform);
	btQuaternion q10 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset10(info.chassis10_offset.x, info.chassis10_offset.y, info.chassis10_offset.z);
	offset10 = offset10.rotate(q10.getAxis(), q10.getAngle());
	chassis10.color = Gray2;
	chassis10.transform.M[12] += offset10.getX();
	chassis10.transform.M[13] += offset10.getY();
	chassis10.transform.M[14] += offset10.getZ();
	//Pieza 12 --------------------------------------------------------------------------------------------
	Cube chassis11(info.chassis11_size.x, info.chassis11_size.y, info.chassis11_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis11.transform);
	btQuaternion q11 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset11(info.chassis11_offset.x, info.chassis11_offset.y, info.chassis11_offset.z);
	offset11 = offset11.rotate(q11.getAxis(), q11.getAngle());
	chassis11.color = Green;
	chassis11.transform.M[12] += offset11.getX();
	chassis11.transform.M[13] += offset11.getY();
	chassis11.transform.M[14] += offset11.getZ();
	//Pieza 13 --------------------------------------------------------------------------------------------
	Cube chassis12(info.chassis12_size.x, info.chassis12_size.y, info.chassis12_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis12.transform);
	btQuaternion q12 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset12(info.chassis12_offset.x, info.chassis12_offset.y, info.chassis12_offset.z);
	offset12 = offset12.rotate(q12.getAxis(), q12.getAngle());
	chassis12.color = Dark_Green;
	chassis12.transform.M[12] += offset12.getX();
	chassis12.transform.M[13] += offset12.getY();
	chassis12.transform.M[14] += offset12.getZ();
	vec3 u2 = { 0,1,0 };
	chassis12.transform.rotate(-30, u2); //INTENTO DE ROTAR (PROBLEMA: ROTA EL OBJETO COMO SI FUESE UN UPDATE)
	//Pieza 14 --------------------------------------------------------------------------------------------
	Cube chassis13(info.chassis13_size.x, info.chassis13_size.y, info.chassis13_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis13.transform);
	btQuaternion q13 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset13(info.chassis13_offset.x, info.chassis13_offset.y, info.chassis13_offset.z);
	offset13 = offset13.rotate(q13.getAxis(), q13.getAngle());
	chassis13.color = Dark_Green;
	chassis13.transform.M[12] += offset13.getX();
	chassis13.transform.M[13] += offset13.getY();
	chassis13.transform.M[14] += offset13.getZ();
	chassis13.transform.rotate(30, u2); //INTENTO DE ROTAR (PROBLEMA: ROTA EL OBJETO COMO SI FUESE UN UPDATE)


	chassis.Render();
	chassis1.Render();
	chassis2.Render();
	chassis3.Render();
	chassis4.Render();
	chassis5.Render();
	chassis6.Render();
	chassis7.Render();
	chassis8.Render();
	chassis9.Render();
	chassis10.Render();
	chassis11.Render();
	chassis12.Render();
	chassis13.Render();

}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}