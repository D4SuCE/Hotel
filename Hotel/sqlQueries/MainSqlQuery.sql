--INSERT INTO Clients (Surname, Name, MiddleName, DateOfBirth, DateOfIssueOfPassport, PassportSeries, PassportID) VALUES ('Antiopova', 'Ludmila', 'Vasilyevna', '12/19/1981', '01/15/1995', 1619, 321893);
--UPDATE Rooms SET DaysOfReservation = 10, ID_Client = (SELECT max(ID_Client) FROM Clients) WHERE TypeOfRoom = 'Business' AND DaysOfReservation = 0 AND ID_Room = (SELECT min(ID_Room) FROM Rooms WHERE DaysOfReservation = 0 AND TypeOfRoom = 'Business');
--SELECT * FROM Rooms WHERE TypeOfRoom = 'Standard' AND DaysOfReservation = 0 AND ID_Room = (SELECT min(ID_Room) FROM Rooms WHERE DaysOfReservation = 0);
--SELECT * FROM Rooms WHERE ID_Room = (SELECT min(ID_Room) FROM Rooms WHERE DaysOfReservation = 0);
--SELECT * FROM Rooms WHERE TypeOfRoom = 'Business' AND DaysOfReservation = 0 AND ID_Room = (SELECT min(ID_Room) FROM Rooms WHERE DaysOfReservation = 0 AND TypeOfRoom = 'Business');

--TRUNCATE TABLE Clients;
--TRUNCATE TABLE Rooms;
--DELETE FROM Clients
--DBCC CHECKIDENT ('HOTEL.dbo.Clients', RESEED, 0)
--SELECT * FROM Rooms WHERE TypeOfRoom = 'Standard' AND DaysOfReservation = 0;
--INSERT INTO Clients (Surname, Name, MiddleName, DateOfBirth, DateOfIssueOfPassport, PassportSeries, PassportID) VALUES ('Antiopova', 'Ludmila', 'Vasilyevna', '12/19/1981', '01/15/1995', 1619, 321893); UPDATE Rooms SET DaysOfReservation = 10, ID_Client = (SELECT max(ID_Client) FROM Clients) WHERE TypeOfRoom = 'Business' AND DaysOfReservation = 0 AND ID_Room = (SELECT min(ID_Room) FROM Rooms WHERE DaysOfReservation = 0 AND TypeOfRoom = 'Business');

--INSERT INTO Rooms (RoomNumber, TypeOfRoom, DaysOfReservation) VALUES
--(10, 'Standard', 0),
--(11, 'Standard', 0),
--(12, 'Standard', 0),
--(13, 'Standard', 0),
--(14, 'Standard', 0),
--(15, 'Standard', 0),
--(20, 'Suite', 0),
--(21, 'Suite', 0),
--(22, 'Suite', 0),
--(23, 'Suite', 0),
--(24, 'Suite', 0),
--(25, 'Suite', 0),
--(30, 'Business', 0),
--(31, 'Business', 0),
--(32, 'Business', 0),
--(33, 'Business', 0),
--(34, 'Business', 0),
--(35, 'Business', 0);

--SELECT RoomNumber FROM Rooms WHERE ID_Client = (SELECT max(ID_Client) FROM Clients);

--SET DATEFORMAT dmy;
--INSERT INTO Clients (Surname, Name, MiddleName, DateOfBirth, DateOfIssueOfPassport, PassportSeries, PassportID) VALUES
--('Абра', 'Кадабра', '', '23.01.2002', '14.02.2002', 1415, 524247);