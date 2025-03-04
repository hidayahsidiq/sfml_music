
#include <SFML/Audio.hpp>
#include <iostream>


void playMusic(const std::filesystem::path& filename)
{
    // Load an ogg,flac,mp3 music file
    // full path with "/" not "\"
    sf::Music music("G:/Music/13 The 1975 The Sound.mp3");

    // Display music information
    std::cout << filename << ":" << '\n'
              << " " << music.getDuration().asSeconds() << " seconds" << '\n'
              << " " << music.getSampleRate() << " samples / sec" << '\n'
              << " " << music.getChannelCount() << " channels" << '\n';

    // Play it
    music.play();

    // Loop while the music is playing
    while (music.getStatus() == sf::Music::Status::Playing)
    {
        // Leave some CPU time for other processes
        sf::sleep(sf::milliseconds(100));

        // Display the playing position
        std::cout << "\rPlaying... " << music.getPlayingOffset().asSeconds() << " sec        " << std::flush;
    }

    std::cout << '\n' << std::endl;
}

void DisplayMenu(){
std::cout << "Menu Options : " << std::endl;
std::cout << "1. Option 1" << std::endl;
std::cout << "2. Option 2" << std::endl;
std::cout << "3. Option 3" << std::endl;
std::cout << "4. Exit" << std::endl;
std::cout << "Enter Your Choice : " ;
}

int main()
{
/*
    int choice ;
    do {
        DisplayMenu();
        std::cin >> choice;
        switch (choice){
        case 1:
            std::cout << "You choose option 1" << std::endl;
            break;
        case 2:
            std::cout << "You choose option 2" << std::endl;
            break;
        case 3:
            std::cout << "You choose option 3" << std::endl;
            break;
        case 4:
            std::cout << "Exiting . . ." << std::endl;
            break;
        default:
            std::cout << "Please try Again !" << std::endl;
        }
    } while(choice != 4);
    */
    // Play music from an ogg file
    //playMusic("test.ogg");

    // Play music from a flac file
    //playMusic("ding.flac");

    // Play music from a mp3 file
    playMusic("13 The 1975 The Sound.mp3");

    // Wait until the user presses 'enter' key
    std::cout << "Press enter to exit..." << std::endl;
    std::cin.ignore(10000, '\n');
    return 0;
}
