#pragma once

#include <GLFW/glfw3.h>
#include <engine/Camera.h>
#include <glad/glad.h>
enum class CursorMode {
    Normal = GLFW_CURSOR_NORMAL,
    Hidden = GLFW_CURSOR_HIDDEN,
    Disabled = GLFW_CURSOR_DISABLED
};

static const std::unordered_map<std::string, CursorMode> stringToCursorMode = {
    {"normal", CursorMode::Normal},
    {"hidden", CursorMode::Hidden},
    {"disabled", CursorMode::Disabled}};
class InputHandler {
  public:
    explicit InputHandler(Camera& camera) : camera_(&camera) {}

    static void setCursorModeFromString(GLFWwindow* window, const std::string& modeString);
    void initialize(GLFWwindow* window);
    void processKeyboard(GLFWwindow* window, float deltaTime);
    void processMouse(double xpos, double ypos);

  private:
    Camera* camera_ = nullptr;
    double lastX_ = 0.0;
    double lastY_ = 0.0;
    bool firstMouse_ = true;

    void setupMouseCapture(GLFWwindow* window);
    void initializeMousePosition(GLFWwindow* window);
    void setInputMode(GLFWwindow* window, int mode, int value);

    static void mouseCallback(GLFWwindow* window, double xpos, double ypos) {
        auto* handler = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        if (handler) {
            handler->processMouse(xpos, ypos);
            SE_LOG_DEBUG("Mouse position: ({}, {})", xpos, ypos);
        }
    }
};
