--Название и продолжительность самого длительного трека.
SELECT name, duration 
FROM musical_track
WHERE duration = (SELECT max(duration) FROM musical_track);
----------------------------------------------------------------
--Название треков, продолжительность которых не менее 3,5 минут.
SELECT name, duration 
FROM musical_track
WHERE duration >= '00:03:30';
------------------------------------------------------------
--Названия сборников, вышедших в период с 2018 по 2020 годы включительно.
SELECT name, release_year
FROM musical_compilation
WHERE release_year BETWEEN '2017-12-31' AND '2021-01-01'
----------------------------------------------------------
--Исполнители, чьё имя состоит из одного слова.
SELECT first_name
FROM performer_name
WHERE last_name = ''; 
----------------------------------------------------
--Название треков, которые содержат слова «мой» или «my».
SELECT name
FROM musical_track
WHERE name LIKE '%my%' OR name LIKE '%мой%';
---------------------------------------------------------------
--Количество исполнителей в каждом жанре.
	
	--Таблица с id-жанров
SELECT genre, COUNT(*)
FROM performers_genres
GROUP BY genre;

	--Подстановка имён и жанров в таблицу performers_genres
SELECT performer_name.first_name, genre.name
FROM performer_name, genre, performers_genres
WHERE performers_genres.genre = genre.id_genre AND performers_genres.performer = performer_name.id_performer_name;

	--Группировка по названиям жанров
SELECT genre.name, COUNT(*) AS performers_count
FROM performer_name, genre, performers_genres
WHERE performers_genres.genre = genre.id_genre AND performers_genres.performer = performer_name.id_performer_name
GROUP BY genre.name ;
---------------------------------------------------------------------

--Количество треков, вошедших в альбомы 2019–2020 годов.

	--Таблица с id-альбомов и количеством треков в них
SELECT album, count(*) AS track_count
FROM musical_track
GROUP BY album;

	--Подстановка имён альбомов 
SELECT album.name AS album_name, count(*) AS track_count
FROM musical_track, album
WHERE musical_track.album = album.id_album 
GROUP BY album.name;

	--Кол-во треков в альбомах 2019-2020 годов
SELECT album.name AS album_name, count(*) AS track_count
FROM musical_track, album
WHERE 	musical_track.album = album.id_album 
		AND album.release_year BETWEEN '2018-12-31' AND '2021-01-01' 
GROUP BY album.name;
------------------------------------------------------------------------------------

--Средняя продолжительность треков по каждому альбому.
SELECT album.name AS album_name, AVG(musical_track.duration) AS AVG_track_duration
FROM musical_track, album
WHERE 	musical_track.album = album.id_album 
GROUP BY album.name;
--------------------------------------------------------------------------------------

--Все исполнители, которые не выпустили альбомы в 2020 году.

	--Подстановка имён альбомов к исполнителям
SELECT performer_name.first_name AS performer, album.name AS album_name
FROM performer_name, album, performers_albums
WHERE 		performers_albums.performer = performer_name.id_performer_name 
		AND performers_albums.album = album.id_album; 
	

SELECT performer_name.first_name AS performer
FROM performer_name, album, performers_albums
WHERE 		performers_albums.performer = performer_name.id_performer_name 
		AND performers_albums.album = album.id_album
		AND album.release_year NOT BETWEEN '2020-01-01' AND '2021-01-01'; 	

--доделать-----------------------------------------------------------------------------------


--Названия сборников, в которых присутствует конкретный исполнитель (выберите его сами).

SELECT musical_compilation.name 
FROM 