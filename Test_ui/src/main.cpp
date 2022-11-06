// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

//--------------------------------------------------

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}



int main(int, char**)
{
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Battle of the coders", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);


    // Our state
    ImVec4 clear_color = ImVec4(0.3f, 0.3f, 0.3f, 1.00f);

    static  char Nickname_buf[64] = ""; 
    bool show_another_window = true;


    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        {
            static int counter = 0;
            //Standard
            static bool C_plus = false;
            static bool bash = false;
            static bool git = false;
            static bool math_plus = false;
            static bool math_sqrt = false;
            
            //Efects
            static bool effects_1 = false;
            static bool effects_2 = false;

            //buf1
            static char buf1[64] = "";

            ImGui::Begin("Testing menu");

            ImGui::BeginChild("##LeftSide", ImVec2(ImGui::GetWindowWidth()/2,ImGui::GetWindowHeight()-40),true);
            

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

            if (ImGui::CollapsingHeader("Rules:"))
            {
                ImGui::Text("Scoring:");
                ImGui::BulletText("match: 3.0 + 0.2 * input_length");
                ImGui::BulletText("no match: -1.0");
            }

            if (ImGui::CollapsingHeader("Standart:"))
            {
                ImGui::Checkbox("C++", &C_plus);
                ImGui::SameLine();
                ImGui::Text("(%d)", counter);


                ImGui::Checkbox("Bash", &bash);
                ImGui::SameLine();
                ImGui::Text("(%d)", counter);

                ImGui::Checkbox("Git", &git);
                ImGui::SameLine();
                ImGui::Text("(%d)", counter);

               ImGui::Checkbox("Math[+]", &math_plus);
               ImGui::SameLine();
               ImGui::Text("(%d)", counter);

               ImGui::Checkbox("Math[sqrt]", &math_sqrt);
               ImGui::SameLine();
               ImGui::Text("(%d)", counter);

        }

            if (ImGui::CollapsingHeader("Battle-Royale:"))
            {
                ImGui::Checkbox("C++[BR]", &C_plus);
                ImGui::SameLine();
                ImGui::Text("(%d)", counter);


                ImGui::Checkbox("Bash[BR]", &bash);
                ImGui::SameLine();
                ImGui::Text("(%d)", counter);

                ImGui::Checkbox("Git[BR]", &git);
                ImGui::SameLine();
                ImGui::Text("(%d)", counter);

               ImGui::Checkbox("Math[+,BR]", &math_plus);
               ImGui::SameLine();
               ImGui::Text("(%d)", counter);

               ImGui::Checkbox("Math[sqrt,BR]", &math_sqrt);
               ImGui::SameLine();
               ImGui::Text("(%d)", counter);

           }

            
           if (ImGui::CollapsingHeader("Effects:"))
           {
            ImGui::Checkbox("First effect", &effects_1);
            ImGui::Checkbox("Second effect", &effects_2);
           }

            ImGui::Separator();
            ImGui::Text("LeaderBoard");
            ImGui::Separator();

            ImGui::BulletText("%s",Nickname_buf);

            ImGui::EndChild();
           
            ImGui::SameLine();

            ImGui::BeginChild("##Center", ImVec2(ImGui::GetWindowWidth()/2,ImGui::GetWindowHeight()-40),true);
            ImGui::BeginChild("##Center_in", ImVec2(ImGui::GetWindowWidth()/1.07,ImGui::GetWindowHeight()-40),true);
    
            ImGui::Text("Game window");
            ImGui::Separator();
            ImGui::EndChild();
           
            ImGui::Separator();
            struct TextFilters
            {
                // Return 0 (pass) if the character is 'i' or 'm' or 'g' or 'u' or 'i'
                static int FilterImGuiLetters(ImGuiInputTextCallbackData* data)
                {
                    if (data->EventChar < 256 && strchr("imgui", (char)data->EventChar))
                        return 0;
                    return 1;
                }
            };


            ImGui::InputText("input",buf1, 64);            
            
            ImGui::EndChild();
            ImGui::End();
        }

        if (show_another_window){
            ImGui::Begin("Nickname");
            ImGui::Text("Plese enter your Nickname:");
            ImGui::Separator();
            struct TextFilters
            {
                // Return 0 (pass) if the character is 'i' or 'm' or 'g' or 'u' or 'i'
                static int FilterImGuiLetters(ImGuiInputTextCallbackData* data)
                {
                    if (data->EventChar < 256 && strchr("imgui", (char)data->EventChar))
                        return 0;
                    return 1;
                }
            };

            
            ImGui::InputText("##1",Nickname_buf, 64);            
            ImGui::SameLine();
            if (ImGui::Button("Enter")){
                show_another_window = false;
            }


            ImGui::End();
        }

        

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
