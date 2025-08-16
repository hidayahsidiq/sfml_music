#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>

int main()
{
    // Daftar playlist (bisa campur format .ogg, .mp3, .wav)
    std::vector<std::string> playlist = {
        "C:/Users/sidiq/Music/The Killers - Mr. Brightside (Official Music Video).mp3",
        "C:/Users/sidiq/Music/Post Malone, Swae Lee - Sunflower (Spider-Man Into the Spider-Verse) (Official Video).mp3",
        "C:/Users/sidiq/Music/Owl City - To The Sky (Official Music Video).mp3"
    };

    if (playlist.empty()) {
        std::cout << "Playlist kosong!" << std::endl;
        return -1;
    }

    sf::Music music;
    int currentIndex = 0;

    auto loadSong = [&](int index) {
        if (!music.openFromFile(playlist[index])) {
            std::cout << "Gagal memuat: " << playlist[index] << std::endl;
            return false;
        }
        std::cout << "Now Playing: " << playlist[index] << std::endl;
        music.play();
        return true;
    };

    // Load lagu pertama
    if (!loadSong(currentIndex)) return -1;

    // Menu loop
    char cmd;
    while (true) {
        std::cout << "\n=== MENU ===\n";
        std::cout << "[P]lay  [U]pause  [S]top  [N]ext  [B]ack  [Q]uit\n";
        std::cout << "Pilihan: ";
        std::cin >> cmd;

        if (cmd == 'P' || cmd == 'p') {
            music.play();
        } else if (cmd == 'U' || cmd == 'u') {
            music.pause();
        } else if (cmd == 'S' || cmd == 's') {
            music.stop();
        } else if (cmd == 'N' || cmd == 'n') {
            currentIndex = (currentIndex + 1) % playlist.size();
            if (!loadSong(currentIndex)) continue;
        } else if (cmd == 'B' || cmd == 'b') {
            currentIndex = (currentIndex - 1 + playlist.size()) % playlist.size();
            if (!loadSong(currentIndex)) continue;
        } else if (cmd == 'Q' || cmd == 'q') {
            break;
        }
    }

    return 0;
}
