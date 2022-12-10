/*
	Impelements the "builder" pattern
	A) Used for building complex objects
	B) Allows inits of params out-of-order
	C) Implements a fluent syntax
	D) Forces construction of object through the builder
	E) For this demo, the object is simple, but ideally this would be implemented for more complex objects

*/

#include <iostream>
#include <string>
#include <vector>

class Song {
	friend SongBuilder;

	std::string name;
	int bpm;
	std::string genre;
	std::string artist;
	int release_year;

public:
	
	std::string getName() { return name; }
	std::string setName(std::string name) { this->name = name; }

	int getBpm() { return bpm; }
	int setBpm(int bpm) { this->bpm = bpm; }

	std::string getGenre() { return genre; }
	std::string setGenre(std::string genre) { this->genre = genre; }

	std::string getArtist() { return artist; }
	std::string setArtist(std::string artist) { this->artist = artist; }

	int getReleaseYear() { return release_year; }
	int setReleaseYear(int release_year) { this->release_year = release_year; }
};

class SongBuilder {
	Song song;

public:
	SongBuilder() {
		song = Song();
	}

	SongBuilder& name(std::string name) {
		song.setName(name);
		return *this;
	}

	SongBuilder& bpm(int bpm) {
		song.setBpm(bpm);
		return *this;
	}

	SongBuilder& genre(std::string genre) {
		song.setGenre(genre);
		return *this;
	}

	SongBuilder& artist(std::string artist) {
		song.setArtist(artist);
		return *this;
	}

	SongBuilder& releaseYear(int releaseYear) {
		song.setReleaseYear(releaseYear);
		return *this;
	}

	Song build() {
		return song;
	}
};


int main()
{
	Song song1 = SongBuilder()
		.name("Some Cool Song!")
		.artist("Strider White")
		.genre("Future Bass")
		.bpm(144)
		.releaseYear(2022)
		.build();
}
