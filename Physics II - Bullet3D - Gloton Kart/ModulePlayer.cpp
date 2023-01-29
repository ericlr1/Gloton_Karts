#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(1.3, 0.15, 2.6); //TAMAÑO
	car.chassis_offset.Set(0, 0.3, 0); //POSICION
	
	car.chassis1_size.Set(0.6, 0.05, 0.4); //TAMAÑO 1
	car.chassis1_offset.Set(0, 0.3, 1.3); //POSICION 1

	car.chassis2_size.Set(1.8, 0.3, 0.3); //TAMAÑO 2
	car.chassis2_offset.Set(0, 0.3, 1.5); //POSICION 2

	car.chassis3_size.Set(0.8, 0.4, 0.45); //TAMAÑO 3
	car.chassis3_offset.Set(0, 0.55, -0.9); //POSICION 3

	car.chassis4_size.Set(0.2, 0.85, 0.2); //TAMAÑO 4
	car.chassis4_offset.Set(-0.5, 0.65, -1.3); //POSICION 4

	car.chassis5_size.Set(0.2, 0.85, 0.2); //TAMAÑO 5
	car.chassis5_offset.Set(0.5, 0.65, -1.3); //POSICION 5

	car.chassis6_size.Set(0.4, 0.4, 0.7); //TAMAÑO 6
	car.chassis6_offset.Set(0.7, 0.3, 0); //POSICION 6

	car.chassis7_size.Set(0.4, 0.4, 0.7); //TAMAÑO 7
	car.chassis7_offset.Set(-0.7, 0.3, 0); //POSICION 7

	car.chassis8_size.Set(0.95, 0.06, 0.75); //TAMAÑO 8
	car.chassis8_offset.Set(0, 0.8, 0.6); //POSICION 8

	car.chassis9_size.Set(0.7, 0.1, 0.75); //TAMAÑO 9
	car.chassis9_offset.Set(0, 0.8, -0.6); //POSICION 9

	car.chassis10_size.Set(0.75, 0.1, 0.7); //TAMAÑO 10
	car.chassis10_offset.Set(0, 0.45, 0); //POSICION 10

	car.chassis11_size.Set(0.6, 0.25, 0.35); //TAMAÑO 11
	car.chassis11_offset.Set(0, 0.9, -0.9); //POSICION 11

	car.chassis12_size.Set(0.5, 0.3, 0.3); //TAMAÑO 2
	car.chassis12_offset.Set(-1, 0.3, 1.4); //POSICION 2

	car.chassis13_size.Set(0.5, 0.3, 0.3); //TAMAÑO 13
	car.chassis13_offset.Set(1, 0.3, 1.4); //POSICION 13

	car.mass = 500.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 1.0f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.16f;
	float wheel_width = 0.2f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.65f;
	float half_length = car.chassis_size.z*0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(0, 0,0);
	
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = 0.0f;
	
	/*if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		App->camera->Position.y += 1;
	}*/

	if(App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		acceleration = MAX_ACCELERATION;
	}
	//Fium de fuerza de drag para el suelo del coche
	if (App->input->GetKey(SDL_SCANCODE_W) == false && f_suelo)
	{
		brake = BRAKE_POWER - 995;
	}
	//Viento a favor de cualquier dirección
	if (App->input->GetKey(SDL_SCANCODE_V) == KEY_DOWN)
	{
		viento_afavor = true;
		viento_contrario = false;
	}
	if (viento_afavor == true && viento)
	{
		acceleration = 0;
		acceleration += 450;
	}
	if (App->input->GetKey(SDL_SCANCODE_B) == KEY_DOWN)
	{
		viento_contrario = true;
		viento_afavor = false;
	}
	if (viento_contrario == true && viento)
	{
		acceleration = 0;
		acceleration -= 450;
	}
	//Neutralizar el viento de cualquier lado.
	if (App->input->GetKey(SDL_SCANCODE_M) == KEY_DOWN)
	{
		viento_contrario = false;
		viento_afavor = false;
	}
	//Viento a favor de cualquier dirección
	if(App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		brake = BRAKE_POWER;
	}

	//Cambiar valores del coche
	if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_REPEAT && App->input->GetKey(SDL_SCANCODE_M) == KEY_DOWN)	//Aumentar gravedad
	{
		gravedad_v--;
		btVector3 aumento(0, gravedad_v, 0);
		
		App->physics->world->setGravity((GRAVITY + aumento) * masa);
		LOG("GRAVITY: %f", (GRAVITY + aumento) * masa);
	}
	if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_REPEAT && App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)	//Reducir gravedad
	{
		gravedad_v++;
		btVector3 aumento(0, gravedad_v, 0);

		App->physics->world->setGravity((GRAVITY + aumento) * masa);
		LOG("GRAVITY: %f", (GRAVITY + aumento) * masa);
	}

	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_REPEAT && App->input->GetKey(SDL_SCANCODE_M) == KEY_DOWN) // Aumentar la masa -> Gravedad afecta mas
	{
		masa++;
		btVector3 aumento(0, gravedad_v, 0);
		App->physics->world->setGravity((GRAVITY + aumento) * masa);
		LOG("Masa: %d", masa)
	}
	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_REPEAT && App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN) // Reducir la masa -> Gravedad afecta menos
	{
		if (masa > 1)
		{
			masa--;
		}
		else
		{
			masa = 1;
		}
		btVector3 aumento(0, gravedad_v, 0);
		App->physics->world->setGravity((GRAVITY + aumento) * masa);
		LOG("Masa: %d", masa)
		
	}

	if (App->input->GetKey(SDL_SCANCODE_F3) == KEY_REPEAT && App->input->GetKey(SDL_SCANCODE_G) == KEY_DOWN) //Toggle on/off gravity
	{
		gravedad = !gravedad;
		if (gravedad)
		{
			btVector3 aumento(0, gravedad_v, 0);
			App->physics->world->setGravity((GRAVITY + aumento) * masa);
		}
		else
		{
			btVector3 no_gravity(0, 0, 0);
			App->physics->world->setGravity(no_gravity);
		}
	}
	if (App->input->GetKey(SDL_SCANCODE_F3) == KEY_REPEAT && App->input->GetKey(SDL_SCANCODE_H) == KEY_DOWN)	//Toggle on/off wind
	{
		viento = !viento;
	}
	if (App->input->GetKey(SDL_SCANCODE_F3) == KEY_REPEAT && App->input->GetKey(SDL_SCANCODE_F) == KEY_DOWN) //Toggle on/off fuerza suelo
	{
		f_suelo = !f_suelo;
	}

	//Calcular la cordenada y del chasis
	auto position_y = vehicle->vehicle->getChassisWorldTransform().getOrigin().getY();
	LOG("Pos_Y: %f", position_y)

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN || position_y < -20)	//Reset posición
	{
		mat4x4 transform;
		transform.rotate(0, vec3(0, 0, 1));
		vehicle->SetTransform(&transform);
		brake = BRAKE_POWER * 3;
	}

	//Aplicar cosas al coche
	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);

	vehicle->Render();

	char title[80];
	sprintf_s(title, "%.1f Km/h", vehicle->GetKmh());
	App->window->SetTitle(title);

	



	return UPDATE_CONTINUE;
}



