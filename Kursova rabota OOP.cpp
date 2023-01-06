#include<iostream>
#include<string>
#include<list>

using namespace std;


class CMusic {
private:
    string performer;
    string song;
    int year;

public:
    
    CMusic() {}

   
    CMusic(int year, string song, string performer) : year(year), song(song), performer(performer) {}

   
    CMusic(const CMusic& other) {
        performer = other.performer;
        song = other.song;
        year = other.year;
    }

    
    string getArtist() const { return performer; }
    string getTitle() const { return song; }
    int getYear() const { return year; }

    
    void output(std::ostream& out) const {
        out << performer << " " << song << " " << year;
    }

    
    void input(std::istream& in) {
        in >> performer >> song >> year;
    }

    
    CMusic& operator=(const CMusic& other) {
        performer = other.performer;
        song = other.song;
        year = other.year;
        return *this;
    }

    
    bool operator<(const CMusic& other) const {
        return year < other.year;
    }

   
    bool operator==(const CMusic& other) const {
        return year == other.year;
    }
};


std::ostream& operator<<(std::ostream& out, const CMusic& music) {
    out << music.getArtist() << " " << music.getTitle() << " " << music.getYear();
    return out;
}


std::istream& operator>>(std::istream& in, CMusic& music) {
    music.input(in);
    return in;
}


class CColl {
private:
    std::list<CMusic> m_listMusic;

public:
    
    CColl(const std::list<CMusic>& l) : m_listMusic(l) {}

    
    CColl() {}

    
    void readIn(std::istream& in) {
        CMusic music;
        while (in >> music) {
            m_listMusic.push_back(music);
        }
    }

    
    void writeTo(std::ostream& out) const {
        for (const CMusic& music : m_listMusic) {
            out << music << std::endl;
        }
    }

   
    int maxCollByYear(const int& year) {
        int count = 0;
        for (const CMusic& music : m_listMusic) {

            
            int maxCollByYear(const int& year) {
                int count = 0;
                for (const CMusic& music : m_listMusic) {
                    if (music.getYear() == year) {
                        count++;
                    }
                }
                return count;
            }

            
            void maxCollByArtist(std::string & artist, int& num) {
                int maxCount = 0;
                for (const CMusic& music : m_listMusic) {
                    int count = 0;
                    for (const CMusic& other : m_listMusic) {
                        if (music.getArtist() == other.getArtist()) {
                            count++;
                        }
                    }
                    if (count > maxCount) {
                        maxCount = count;
                        artist = music.getArtist();
                    }
                }
                num = maxCount;
            }
        };


        int main() {
            
            std::list<CMusic> musicList = {
                CMusic(2018, "MIHAELA1", "MIHAELA"),
                CMusic(2008, "BTR1", "BTR"),
                CMusic(2005, "BTR4", "BTR"),
                CMusic(2008, "BTR5", "BTR"),
                CMusic(2016, "MIRO1", "MIRO")
            };
            CColl coll(musicList);

           
            cout << "COLLECTION IN YEAR 2008: " << coll.maxCollByYear(2008) << std::endl;

            std::string artist;
            int num;
            coll.maxCollByArtist(artist, num);
            cout << "MAX COLLECTION BY ARTIST: " << artist << " " << num << std::endl;

            return 0;
        }
