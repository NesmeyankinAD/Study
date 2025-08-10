CREATE TABLE IF NOT EXISTS genre (
	id_genre 	SERIAL PRIMARY KEY,
	name 		VARCHAR(50) NOT NULL UNIQUE 
);

CREATE TABLE IF NOT EXISTS performer_name (
	id_performer_name 	SERIAL PRIMARY KEY,
	name 				VARCHAR(50) NOT NULL UNIQUE
);

CREATE TABLE IF NOT EXISTS album (
	id_album 	SERIAL PRIMARY KEY,
	name 			VARCHAR(50) NOT NULL,
	release_year 	DATE NOT NULL
);

CREATE TABLE IF NOT EXISTS compilation_name (
	id_compilation_name SERIAL PRIMARY KEY,
	name 				VARCHAR(50) NOT NULL 
);


CREATE TABLE IF NOT EXISTS performers_genres (
	performer 		INTEGER REFERENCES performer_name(id_performer_name),
	genre 			INTEGER REFERENCES genre(id_genre),
	PRIMARY KEY (performer, genre)
);

CREATE TABLE IF NOT EXISTS performers_albums (
	performer 	INTEGER REFERENCES performer_name(id_performer_name),
	album 		INTEGER REFERENCES album(id_album),
	PRIMARY KEY (performer, album)
);

CREATE TABLE IF NOT EXISTS musical_track (
	id_musical_track 	SERIAL PRIMARY KEY,
	name 				VARCHAR(50) NOT NULL,
	duration			TIME NOT NULL,
	album 				INTEGER REFERENCES album(id_album)
);

CREATE TABLE IF NOT EXISTS musical_compilation (
	id_musical_compilation 	SERIAL PRIMARY KEY,
	name 					INTEGER REFERENCES compilation_name(id_compilation_name),
	release_year 			DATE NOT NULL,
	musical_track 			INTEGER REFERENCES musical_track(id_musical_track)
);

