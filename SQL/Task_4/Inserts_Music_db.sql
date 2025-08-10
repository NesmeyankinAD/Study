--добавление жанров
INSERT INTO genre(name)
VALUES('Жанр4');

--добавление исполнителей
INSERT INTO performer_name(first_name, last_name)
VALUES('Исполнитель7', 'Фамилия7');

UPDATE performer_name
SET first_name = 'Исполнитель7'
WHERE id_performer_name = 7;

UPDATE performer_name
SET last_name = ''
WHERE id_performer_name = 4;

--добавление соответствий жанр-исполнитель
INSERT INTO performers_genres(performer, genre)
VALUES(7, 3);

--добавление альбомов
INSERT INTO album(name, release_year)
VALUES('Альбом5', '2019-01-11');

--добавление соответствий альбом-исполнитель
INSERT INTO performers_albums(performer, album)
VALUES(4, 5);

--добавление треков
INSERT INTO musical_track(name, duration, album)
VALUES('Трек22', '00:04:00', 5);

UPDATE musical_track
SET duration = '00:04:40'
WHERE id_musical_track = 19;

UPDATE musical_track
SET name = 'my Трек2'
WHERE id_musical_track = 2;

--добавление имён сборников
INSERT INTO compilation_name(name)
VALUES('Сборник5');

INSERT INTO compilation_name
VALUES(5, 'Сборник5');

--создание сборников
--сборник1
INSERT INTO musical_compilation(name, release_year, musical_track)
VALUES(1, '2007-01-21', 19);

--сборник2
INSERT INTO musical_compilation(name, release_year, musical_track)
VALUES(2, '2009-02-22', 20);

--сборник3
INSERT INTO musical_compilation(name, release_year, musical_track)
VALUES(3, '2012-03-23', 19);

--сборник4
INSERT INTO musical_compilation(name, release_year, musical_track)
VALUES(4, '2013-04-24', 18);

--сборник5
INSERT INTO musical_compilation(name, release_year, musical_track)
VALUES(5, '2019-06-01', 3);

INSERT INTO musical_compilation
VALUES(37, 5, '2019-06-01', 15);