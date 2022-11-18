#include <iostream>
#include <string>
#include "VulkanShaderApp.h"

using namespace std;

bool ignoreOptions()
{
    string input;
    cout << "Press s for starting with default model and texture... " << endl;
    cout << "Waiting for input... " << endl;
    cin >> input;
    if (input == "s" || input == "S")
    {
        return true;
    }
    return false;
}

string SetTexture()
{
    int input;
    cout << "Which texture do you want?" << endl;
    cout << "Press 0 (also default) for viking room texture" << endl;
    cout << "Press 1 for among us texture" << endl;
    cout << "Press 2 for smile texture" << endl;
    cout << "Press 3 for sculpture head texture" << endl;
    cout << "Waiting for input... " << endl;
    cin >> input;

    if (input == 1) { return "textures/au.png"; }

    else if (input == 2) { return "textures/smile.png"; }

    else if (input == 3) { return "textures/textureOrg.jpg"; }

    return "textures/viking_room.png";
}

bool isRotatingInputActive()
{
    string input;
    cout << "Press r for rotating object or anything else to make stationary... " << endl;
    cout << "Waiting for input... " << endl;
    cin >> input;
    if (input == "r" || input == "R")
    {
        return true;
    }
    return false;
}

float SetModelScale()
{
    float input;
    cout << "Select scale of model, default is 1. Min: 0.3, Max: 7" << endl;
    cout << "Waiting for input... " << endl;
    cin >> input;

    return std::clamp(input, 0.3f, 7.0f);
}

int startApp()
{
    VulkanShaderApp app;

    bool readyToStart = ignoreOptions();
    if (!readyToStart)
    {
        app.TEXTURE_PATH = SetTexture();
        app.bRotating = isRotatingInputActive();
        app.modelScale = SetModelScale();
    }
    cout << "Window is loading... Close the vulkan window if you wish to restart" << endl;

    try
    {
        app.run();
    }
    catch (const exception& e)
    {
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }
    startApp(); // restart if vulkan window closes

    return EXIT_SUCCESS;
}

int main()
{
    return startApp();

}