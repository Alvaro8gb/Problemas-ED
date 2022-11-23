#ifndef IPUD
#define IPUD

#include <unordered_map>
#include <stdexcept>
#include <list>

class IPud {
private:

    using Song = std::string;
    using Artista = std::string;
    using ListSong = std::list <Song>;

    using infoSong = struct {
        Artista artista;
        int duracion;
        ListSong:: iterator itPlayList;
        ListSong:: iterator itPlayedList;
    };

    using PlayList = std::pair< ListSong, int>;
    using TablaCanciones = std::unordered_map <Song, infoSong>;  

    TablaCanciones canciones;
    PlayList playList;
    ListSong playedList;

public:
    
    IPud() { } //creacion de IPud vacio

    void addSong(Song const & song, Artista const& a, int duracion) {// O(1)
   
        auto it = canciones.insert({ song,{a,duracion, playList.first.end(),playedList.end()} });

        if (!it.second) throw  std::domain_error("Cancion ya existente en el IPud");

    }
    void addToPlaylist(Song song) {
      
        auto it = canciones.find(song);

        if (it == canciones.end()) throw std::domain_error("Cancion no esta en el IPud");

        if (it->second.itPlayList == playList.first.end()) {

            playList.first.push_back(song);
            playList.second += it->second.duracion;
            auto itList = --playList.first.end();
            it->second.itPlayList = itList;

        }

    }
    Song play() {
;
        if (playList.first.empty()) return "No hay canciones en la lista";

        Song song = playList.first.front();
        auto& infoCancion = canciones[song];

        playList.second -= infoCancion.duracion;
        infoCancion.itPlayList = playList.first.end();
        playList.first.pop_front();

        if (infoCancion.itPlayedList != playedList.end()) playedList.erase(infoCancion.itPlayedList);
        
        playedList.push_front(song);
        infoCancion.itPlayedList = playedList.begin();

        return "Sonando " + song;
    }
    Song current() {
        if (playList.first.empty()) throw std::domain_error("PlayList vacia");

        return playList.first.front();
    }
    int totalTime() const{
        return playList.second;
    }
    void deleteSong(Song song) {

        auto it = canciones.find(song);

        if (it != canciones.end()) {
            auto& infoSong = it->second;

            if (infoSong.itPlayList != playList.first.end()) {
                playList.second -= infoSong.duracion;
                playList.first.erase(infoSong.itPlayList);
            }

            if(infoSong.itPlayedList != playedList.end()) playedList.erase(infoSong.itPlayedList);

            canciones.erase(song); 
        }

    }

    ListSong recent(int n) {
        ListSong nRecentSongs;
        auto it = playedList.begin();
        int i = 0;

        while (i < n && it != playedList.end()) {
            nRecentSongs.push_back(*it);
            i++;
            it++;
        }

        return nRecentSongs;

    }
};


#endif

