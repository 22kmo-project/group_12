-- MySQL dump 10.13  Distrib 8.0.30, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: banksimuldb_exp
-- ------------------------------------------------------
-- Server version	8.0.29

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `accesslist`
--

DROP TABLE IF EXISTS `accesslist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `accesslist` (
  `idaccesslist` int unsigned NOT NULL AUTO_INCREMENT,
  `id_user` int unsigned NOT NULL,
  `account_number` int unsigned NOT NULL,
  PRIMARY KEY (`idaccesslist`),
  KEY `user_id_idx` (`id_user`),
  KEY `account_number_idx` (`account_number`),
  CONSTRAINT `account_number` FOREIGN KEY (`account_number`) REFERENCES `bankaccount` (`account_number`),
  CONSTRAINT `id_user` FOREIGN KEY (`id_user`) REFERENCES `bankuser` (`id_user`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb3 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `accesslist`
--

LOCK TABLES `accesslist` WRITE;
/*!40000 ALTER TABLE `accesslist` DISABLE KEYS */;
INSERT INTO `accesslist` VALUES (2,1,100),(3,2,102),(4,1,100),(5,1,100),(6,1,100);
/*!40000 ALTER TABLE `accesslist` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bankaccount`
--

DROP TABLE IF EXISTS `bankaccount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `bankaccount` (
  `account_number` int unsigned NOT NULL AUTO_INCREMENT,
  `id_user` int unsigned NOT NULL,
  `balance` int NOT NULL,
  `credit` bit(1) NOT NULL,
  `credit_cap` int unsigned NOT NULL,
  PRIMARY KEY (`account_number`),
  KEY `user_id_idx` (`id_user`),
  CONSTRAINT `id_user_acc` FOREIGN KEY (`id_user`) REFERENCES `bankuser` (`id_user`)
) ENGINE=InnoDB AUTO_INCREMENT=108 DEFAULT CHARSET=utf8mb3 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bankaccount`
--

LOCK TABLES `bankaccount` WRITE;
/*!40000 ALTER TABLE `bankaccount` DISABLE KEYS */;
INSERT INTO `bankaccount` VALUES (100,1,640,_binary '\0',0),(101,2,2000,_binary '\0',0),(102,3,1918,_binary '\0',0),(103,4,1880,_binary '\0',0),(104,4,2000,_binary '\0',0),(107,2,100000,_binary '\0',0);
/*!40000 ALTER TABLE `bankaccount` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bankuser`
--

DROP TABLE IF EXISTS `bankuser`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `bankuser` (
  `id_user` int unsigned NOT NULL AUTO_INCREMENT,
  `fname` varchar(50) CHARACTER SET utf8mb3 COLLATE utf8_bin NOT NULL,
  `lname` varchar(50) CHARACTER SET utf8mb3 COLLATE utf8_bin NOT NULL,
  `streetname` varchar(50) CHARACTER SET utf8mb3 COLLATE utf8_bin NOT NULL,
  `zipcode` varchar(5) CHARACTER SET utf8mb3 COLLATE utf8_bin NOT NULL,
  `city` varchar(45) CHARACTER SET utf8mb3 COLLATE utf8_bin NOT NULL,
  `phonenumber` varchar(10) CHARACTER SET utf8mb3 COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`id_user`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb3 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bankuser`
--

LOCK TABLES `bankuser` WRITE;
/*!40000 ALTER TABLE `bankuser` DISABLE KEYS */;
INSERT INTO `bankuser` VALUES (1,'Matti','Meikäläinen','Esimerkkikatu 123','01234','Malli','0123456789'),(2,'Maija','Mehilänen','Esimerkkikatu 124','01234','Malli','0123456788'),(3,'Pekka','Pouta','Esimerkkikatu 124','01234','Malli','0123456787'),(4,'Halla','Pakkanen','Esimerkkikatu 125','01234','Malli','0123456786');
/*!40000 ALTER TABLE `bankuser` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `card`
--

DROP TABLE IF EXISTS `card`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `card` (
  `card_number` int unsigned NOT NULL AUTO_INCREMENT,
  `card_owner` varchar(45) CHARACTER SET utf8mb3 COLLATE utf8_bin NOT NULL,
  `expiry_date` date NOT NULL,
  `pincode` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8_bin NOT NULL,
  `debit` bit(1) NOT NULL,
  `credit` bit(1) NOT NULL,
  `locked_pin` bit(1) NOT NULL,
  PRIMARY KEY (`card_number`)
) ENGINE=InnoDB AUTO_INCREMENT=114 DEFAULT CHARSET=utf8mb3 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `card`
--

LOCK TABLES `card` WRITE;
/*!40000 ALTER TABLE `card` DISABLE KEYS */;
INSERT INTO `card` VALUES (100,'Matti Meikäläinen','2025-12-01','$2a$10$VutWUfLro93SoJ5W5Joe8OwIwVc58Ekld0zo0EII6z5nZlnQnIm4i',_binary '',_binary '\0',_binary '\0'),(101,'Maija Mehiläinen','2021-11-01','$2a$10$a4JfpN1TOOzsRgI3MzHwBe7LyjE3wKOGPqpCZ7jquYcFqPAmkg8qe',_binary '\0',_binary '',_binary '\0'),(102,'Halla Pakkanen','2025-12-01','$2a$10$mzwdst/KAY3YP7E42Ej2P.8t0N3uzlKlQbeDFiVjqPmZaQe5iNwKy',_binary '\0',_binary '',_binary '\0'),(103,'Pekka Pouta','2030-06-01','$2a$10$1MgIYwUGzjV8KH7Id07IPOwVQDpm6UYTU7BmslExSRB4eb../BrRq',_binary '',_binary '',_binary '\0'),(104,'Risto Räppääjä','2030-11-01','$2a$10$0O9UXzPq7b/Sw/H5kq916OqubbIw4YH3qNugsqqtkNMSJFn2huT0a',_binary '',_binary '\0',_binary '\0'),(105,'Pekka Pouta','2030-06-01','$2a$10$ZvVOAZHiqKQt5N62URVGT.NHlPYj5yM5BfUahn4rlwCZsL5bcGjTq',_binary '',_binary '',_binary '\0'),(111,'Uuno Turhaporo','2040-11-11','$2a$10$7tW7RTsUmDnkAlHIc19Ay.XmnB9kDIVFgiwSAMYDaecvqHxWcMV9e',_binary '',_binary '\0',_binary '\0'),(113,'Uuno Turhaporo','2040-11-11','$2a$10$wF7g0g6bisrJNaF73SIPvurInVHqoE82Mu.ZHDl85LPAiAsUCzLaK',_binary '',_binary '\0',_binary '\0');
/*!40000 ALTER TABLE `card` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `card_access`
--

DROP TABLE IF EXISTS `card_access`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `card_access` (
  `idcard_access` int unsigned NOT NULL AUTO_INCREMENT,
  `account_number` int unsigned NOT NULL,
  `card_number` int unsigned NOT NULL,
  PRIMARY KEY (`idcard_access`),
  KEY `account_number_idx` (`account_number`),
  KEY `card_number_idx` (`card_number`),
  CONSTRAINT `account_number_card` FOREIGN KEY (`account_number`) REFERENCES `bankaccount` (`account_number`),
  CONSTRAINT `card_number_card` FOREIGN KEY (`card_number`) REFERENCES `card` (`card_number`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb3 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `card_access`
--

LOCK TABLES `card_access` WRITE;
/*!40000 ALTER TABLE `card_access` DISABLE KEYS */;
INSERT INTO `card_access` VALUES (2,100,100),(3,102,111),(4,103,103),(5,102,111),(6,103,104),(7,104,104);
/*!40000 ALTER TABLE `card_access` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transactions`
--

DROP TABLE IF EXISTS `transactions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transactions` (
  `idtransactions` int unsigned NOT NULL AUTO_INCREMENT,
  `description` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8_bin DEFAULT NULL,
  `account_number` int unsigned NOT NULL,
  `card_number` int unsigned NOT NULL,
  `amount` int NOT NULL,
  `date_time` datetime NOT NULL,
  PRIMARY KEY (`idtransactions`),
  KEY `account_number_idx` (`account_number`),
  KEY `card_number_trans_idx` (`card_number`),
  CONSTRAINT `account_number_trans` FOREIGN KEY (`account_number`) REFERENCES `bankaccount` (`account_number`),
  CONSTRAINT `card_number_trans` FOREIGN KEY (`card_number`) REFERENCES `card` (`card_number`)
) ENGINE=InnoDB AUTO_INCREMENT=89 DEFAULT CHARSET=utf8mb3 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transactions`
--

LOCK TABLES `transactions` WRITE;
/*!40000 ALTER TABLE `transactions` DISABLE KEYS */;
INSERT INTO `transactions` VALUES (2,'ATM Withdrawal',101,101,50,'2022-12-01 17:49:36'),(3,'ATM Withdrawal',100,100,20,'2022-12-01 17:36:30'),(4,'ATM Withdrawal',100,100,20,'2022-12-01 17:37:07'),(5,'ATM Withdrawal',100,100,20,'2022-12-01 17:41:34'),(6,'ATM Withdrawal',100,100,20,'2022-12-01 17:41:35'),(7,'ATM Withdrawal',100,100,20,'2022-12-01 17:41:36'),(8,'ATM Withdrawal',100,100,20,'2022-12-01 17:41:37'),(9,'ATM Withdrawal',100,100,20,'2022-12-01 17:41:38'),(10,'withdrawal',100,100,20,'2022-12-08 15:22:09'),(11,'withdrawal',100,100,20,'2022-12-08 15:40:05'),(12,'withdrawal',100,100,20,'2022-12-08 16:03:00'),(13,'withdrawal',100,100,20,'2022-12-08 16:04:13'),(14,'withdrawal',100,100,20,'2022-12-08 16:15:45'),(15,'withdrawal',100,100,20,'2022-12-08 16:18:00'),(16,'withdrawal',100,100,20,'2022-12-08 16:22:04'),(17,'withdrawal',100,100,20,'2022-12-08 16:31:53'),(18,'withdrawal',100,100,500,'2022-12-08 16:32:10'),(19,'withdrawal',100,100,20,'2022-12-08 16:52:50'),(20,'withdrawal',100,100,20,'2022-12-08 16:53:18'),(21,'withdrawal',100,100,20,'2022-12-08 16:54:16'),(22,'withdrawal',100,100,20,'2022-12-08 16:54:58'),(23,'withdrawal',100,100,500,'2022-12-08 16:55:56'),(24,'withdrawal',100,100,20,'2022-12-08 16:57:08'),(25,'withdrawal',100,100,20,'2022-12-08 17:06:07'),(26,'withdrawal',100,100,20,'2022-12-08 17:07:09'),(27,'withdrawal',103,104,20,'2022-12-08 18:22:25'),(28,'withdrawal',103,104,60,'2022-12-08 18:23:04'),(29,'withdrawal',103,104,40,'2022-12-08 18:29:13'),(30,'withdrawal',100,100,20,'2022-12-09 17:38:08'),(31,'withdrawal',102,111,20,'2022-12-09 17:46:52'),(32,'withdrawal',102,111,20,'2022-12-09 17:51:26'),(33,'withdrawal',102,111,1,'2022-12-09 17:53:19'),(34,'withdrawal',102,111,1,'2022-12-09 18:10:51'),(35,'withdrawal',102,111,20,'2022-12-09 18:15:54'),(36,'withdrawal',102,111,1,'2022-12-09 18:18:19'),(37,'withdrawal',102,111,1,'2022-12-09 18:19:32'),(38,'withdrawal',102,111,1,'2022-12-09 18:20:51'),(39,'withdrawal',102,111,1,'2022-12-09 18:30:45'),(40,'withdrawal',102,111,0,'2022-12-09 18:34:09'),(41,'withdrawal',102,111,1,'2022-12-09 18:37:35'),(42,'withdrawal',102,111,1,'2022-12-09 18:47:23'),(43,'withdrawal',102,111,1,'2022-12-09 18:48:16'),(44,'withdrawal',102,111,1,'2022-12-10 12:33:21'),(45,'withdrawal',102,111,20,'2022-12-10 12:34:38'),(46,'withdrawal',102,111,20,'2022-12-10 13:06:19'),(47,'withdrawal',102,111,1,'2022-12-10 13:07:07'),(48,'withdrawal',102,111,1,'2022-12-10 18:46:44'),(49,'withdrawal',102,111,0,'2022-12-10 18:48:43'),(50,'withdrawal',102,111,0,'2022-12-10 21:14:41'),(51,'withdrawal',102,111,1,'2022-12-10 21:28:22'),(52,'withdrawal',102,111,0,'2022-12-10 21:39:45'),(53,'withdrawal',102,111,0,'2022-12-11 12:17:46'),(54,'withdrawal',102,111,1,'2022-12-11 17:57:31'),(55,'withdrawal',102,111,0,'2022-12-11 19:19:39'),(56,'withdrawal',102,111,0,'2022-12-11 20:29:24'),(57,'withdrawal',102,111,20,'2022-12-11 23:11:54'),(58,'withdrawal',102,111,40,'2022-12-11 23:11:56'),(59,'Withdrawal',102,111,1,'2022-12-11 23:16:38'),(60,'Withdrawal',102,111,2,'2022-12-11 23:16:41'),(61,'Withdrawal',102,111,3,'2022-12-11 23:16:42'),(62,'Withdrawal',102,111,4,'2022-12-11 23:16:44'),(63,'Withdrawal',102,111,5,'2022-12-11 23:16:45'),(64,'Withdrawal',102,111,1,'2022-12-12 13:00:32'),(65,'Withdrawal',102,111,20,'2022-12-12 13:58:18'),(66,'Withdrawal',102,111,20,'2022-12-12 14:00:21'),(67,'Withdrawal',102,111,40,'2022-12-12 14:01:05'),(68,'Withdrawal',102,111,0,'2022-12-12 14:11:05'),(69,'Withdrawal',102,111,1,'2022-12-12 14:11:14'),(70,'Withdrawal',102,111,0,'2022-12-12 14:17:54'),(71,'Withdrawal',102,111,1,'2022-12-12 14:22:45'),(72,'Withdrawal',102,111,20,'2022-12-12 14:23:26'),(73,'Withdrawal',102,111,20,'2022-12-12 14:23:45'),(74,'Withdrawal',102,111,20,'2022-12-12 15:47:23'),(75,'Withdrawal',102,111,40,'2022-12-12 15:48:16'),(76,'Withdrawal',102,111,60,'2022-12-12 15:48:19'),(77,'Withdrawal',102,111,100,'2022-12-12 15:48:23'),(78,'Withdrawal',102,111,200,'2022-12-12 15:48:26'),(79,'Withdrawal',102,111,500,'2022-12-12 15:48:28'),(80,'Withdrawal',102,111,500,'2022-12-12 15:48:30'),(81,'Withdrawal',102,111,200,'2022-12-12 15:48:37'),(82,'Withdrawal',102,111,60,'2022-12-12 15:48:44'),(83,'Withdrawal',102,111,1,'2022-12-12 15:50:44'),(84,'Withdrawal',102,111,1,'2022-12-12 16:06:02'),(85,'Withdrawal',102,111,1,'2022-12-12 16:37:46'),(86,'Withdrawal',102,111,20,'2022-12-12 16:39:19'),(87,'Withdrawal',102,111,20,'2022-12-12 16:48:54'),(88,'Withdrawal',102,111,40,'2022-12-12 16:48:57');
/*!40000 ALTER TABLE `transactions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'banksimuldb_exp'
--
/*!50003 DROP PROCEDURE IF EXISTS `withdrawal` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `withdrawal`(IN accountnumber INT, IN cardnumber INT,  IN amount INT )
BEGIN
DECLARE test1 INT DEFAULT 0;
START TRANSACTION;
UPDATE bankaccount SET balance = balance-amount WHERE account_number=accountnumber AND balance-amount >= 0;
SET test1=row_count();
	IF (test1 > 0) THEN
		COMMIT;
		INSERT INTO transactions(description, account_number, card_number, amount, date_time) VALUES('Withdrawal', accountnumber, cardnumber, amount, NOW());
    ELSE
		ROLLBACK;
	END IF;
    END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-12-12 16:56:00
