#include <windows.h>
#include <string>
#include <stack>
#include <vector>

using namespace std;

enum ControlIDs {
    ID_GO_BUTTON = 1,
    ID_BACK_BUTTON = 2,
    ID_FORWARD_BUTTON = 3
};

struct UIComponents {
    HWND addressInput;
    HWND statusDisplay;
    HWND backButton;
    HWND forwardButton;
    HWND goButton;
};

class BrowserHistory {
private:
    stack<string> back_stack;
    stack<string> forward_stack;
    string current_url;

public:
    BrowserHistory() {
        current_url = "Home Page";
    }

    void visit(string url) {
        if (!current_url.empty()) {
            back_stack.push(current_url);
        }
        current_url = url;
        while (!forward_stack.empty()) {
            forward_stack.pop();
        }
    }

    void back() {
        if (!back_stack.empty()) {
            forward_stack.push(current_url);
            current_url = back_stack.top();
            back_stack.pop();
        }
    }

    void forward() {
        if (!forward_stack.empty()) {
            back_stack.push(current_url);
            current_url = forward_stack.top();
            forward_stack.pop();
        }
    }

    string getCurrent() { return current_url; }
    bool canBack() { return !back_stack.empty(); }
    bool canForward() { return !forward_stack.empty(); }
};

BrowserHistory browserHistory;
UIComponents ui;

void RefreshInterface() {
    SetWindowTextA(ui.statusDisplay, ("Current: " + browserHistory.getCurrent()).c_str());
    EnableWindow(ui.backButton, browserHistory.canBack());
    EnableWindow(ui.forwardButton, browserHistory.canForward());
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE:
        CreateWindowA("static", "Enter URL:", WS_VISIBLE | WS_CHILD, 20, 20, 80, 25, hwnd, NULL, NULL, NULL);
        ui.addressInput = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 100, 20, 240, 25, hwnd, NULL, NULL, NULL);
        ui.goButton = CreateWindowA("button", "Go", WS_VISIBLE | WS_CHILD, 350, 20, 60, 25, hwnd, (HMENU)ID_GO_BUTTON, NULL, NULL);
        
        ui.backButton = CreateWindowA("button", "Back", WS_VISIBLE | WS_CHILD, 20, 65, 80, 35, hwnd, (HMENU)ID_BACK_BUTTON, NULL, NULL);
        ui.forwardButton = CreateWindowA("button", "Forward", WS_VISIBLE | WS_CHILD, 110, 65, 90, 35, hwnd, (HMENU)ID_FORWARD_BUTTON, NULL, NULL);
        
        ui.statusDisplay = CreateWindowA("static", "Current: Home Page", WS_VISIBLE | WS_CHILD, 20, 120, 400, 40, hwnd, NULL, NULL, NULL);
        RefreshInterface();
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case ID_GO_BUTTON: {
            char buffer[256];
            GetWindowTextA(ui.addressInput, buffer, 256);
            if (strlen(buffer) > 0) {
                browserHistory.visit(buffer);
                SetWindowTextA(ui.addressInput, "");
                RefreshInterface();
            }
            break;
        }
        case ID_BACK_BUTTON:
            browserHistory.back();
            RefreshInterface();
            break;
        case ID_FORWARD_BUTTON:
            browserHistory.forward();
            RefreshInterface();
            break;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "BrowserHistoryWindow";
    WNDCLASSA wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClassA(&wc);

    HWND hwnd = CreateWindowExA(0, CLASS_NAME, "Browser History Simulator", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 450, 220, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) return 0;

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
