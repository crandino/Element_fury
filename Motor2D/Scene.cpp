#include "p2Defs.h"
#include "p2Log.h"
#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"


#define FRAME_LOGIC 60
#define MS_PER_LOGIC_FRAME 1000.0f/FRAME_LOGIC

Scene::Scene() : Module()
{
	name.create("scene");
}

// Destructor
Scene::~Scene()
{}

// Called before render is available
bool Scene::awake(pugi::xml_node &node)
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool Scene::start()
{
	return true;
}

// Called each loop iteration
bool Scene::preUpdate()
{
	return true;
}

// Called each loop iteration
bool Scene::update(float dt)
{
	float cam_speed = ceil(25.0f * (dt/MS_PER_LOGIC_FRAME));

	/*if (app->input->getKey(SDL_SCANCODE_L) == KEY_DOWN)
		app->loadGame("save_game.xml");

	if (app->input->getKey(SDL_SCANCODE_K) == KEY_DOWN)
		app->saveGame("save_game.xml");*/

	if (app->input->getKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		app->render->camera.y += cam_speed;

	if (app->input->getKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		app->render->camera.y -= cam_speed;

	if (app->input->getKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		app->render->camera.x += cam_speed;

	if (app->input->getKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		app->render->camera.x -= cam_speed;

	if (app->input->getKey(SDL_SCANCODE_KP_PLUS) == KEY_UP)
		app->audio->volumeUp();

	if (app->input->getKey(SDL_SCANCODE_KP_MINUS) == KEY_UP)
		app->audio->volumeDown();

	return true;
}

// Called each loop iteration
bool Scene::postUpdate()
{
	bool ret = true;

	if(app->input->getKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool Scene::cleanUp()
{
	LOG("Freeing scene");
	return true;
}