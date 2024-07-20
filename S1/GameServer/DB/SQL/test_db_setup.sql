use test;
-- 각 테이블의 TIMESTAMP 타입인 컬럼들은 붙은 옵션에 의해 자동으로 NOT NULL 속성이 부여됨 

-- 자식 테이블 먼저 삭제
DROP TABLE IF EXISTS user_characters;
    
-- 부모 테이블 삭제
DROP TABLE IF EXISTS user_accounts;
    
-- 나머지 테이블 삭제
DROP TABLE IF EXISTS user_test;   
DROP TABLE IF EXISTS user_items;   
DROP TABLE IF EXISTS item_weapons,item_armors,item_accesories;   



-- 유저 계정 테이블 생성
CREATE TABLE user_accounts
(
    id         INT AUTO_INCREMENT UNIQUE,
    user_id    VARCHAR(24) PRIMARY KEY,
    username   VARCHAR(50)  NOT NULL UNIQUE,
    password   VARCHAR(255) NOT NULL,
    email      VARCHAR(100) NOT NULL UNIQUE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);


-- 유저 계정 데이터 삽입
INSERT INTO user_accounts (user_id, username, password, email) VALUES
('admin', 'admin', 'admin', 'admin@test.com'),
('user_1', 'john_doe', 'securepassword1', 'john@test.com'),
('user_2', 'jane_doe', 'securepassword2', 'jane@test.com');



-- 유저 캐릭터 테이블 생성
CREATE TABLE user_characters
(
    profile_id     INT AUTO_INCREMENT PRIMARY KEY,
    user_id        INT         NOT NULL,
    character_name VARCHAR(50) NOT NULL UNIQUE,
    level          INT       DEFAULT 1,
    experience     BIGINT    DEFAULT 0,
    gold           BIGINT    DEFAULT 0,
    created_at     TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at     TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES user_accounts (id)
);
-- 유저 캐릭터 데이터 삽입
INSERT INTO user_characters (user_id, character_name, level, experience, gold) VALUES
(1, 'admin', 1, 0, 500),
(2, 'user1', 1, 0, 500);



-- 유저 아이템 테이블 생성
DROP TABLE IF EXISTS user_items;
CREATE TABLE user_items
(
    profile_id INT NOT NULL,
    item_id    INT NOT NULL,
    item_quantity INT DEFAULT 0,
    item_type  INT NOT NULL COMMENT 'weapon = 1, armor = 2, accesorries = 3, skin = 4 ...',
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP COMMENT 'Item Creation Time',
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT 'Item Last Update Time'
);



-- 아이템_무기 테이블 생성
DROP TABLE IF EXISTS item_weapons;
CREATE TABLE item_weapons
(
    item_id INT PRIMARY KEY,
    item_name VARCHAR(30) NOT NULL,
    item_description TEXT,
    attack_power INT,
    item_effect INT DEFAULT NULL
);
-- 아이템_무기 데이터 삽입
INSERT INTO item_weapons (item_id, item_name, item_description, attack_power, item_effect) VALUES
(1, 'Sword', 'A sharp blade.', 50, NULL),
(2, 'Dagger', 'A sharp blade.', 50, NULL),
(3, 'Spear', 'A sharp blade.', 50, NULL);


-- 아이템_갑옷 테이블 생성
DROP TABLE IF EXISTS item_armors;
CREATE TABLE item_armors
(
    item_id INT PRIMARY KEY,
    item_name VARCHAR(30) NOT NULL,
    item_description TEXT,
    defense_power INT,
    item_effect INT DEFAULT NULL
);
-- 아이템_갑옷 데이터 삽입
INSERT INTO item_armors (item_id, item_name, item_description, defense_power, item_effect) VALUES
(1, 'fabric Armor', 'A sturdy shield.', 30, NULL),
(2, 'Leather Armor', 'A sturdy shield.', 30, NULL),
(3, 'Iron Armor', 'A sturdy shield.', 30, NULL);



-- 아이템_장신구 테이블 생성
DROP TABLE IF EXISTS item_accesories;
CREATE TABLE item_accesories
(
    item_id INT PRIMARY KEY,
    item_name VARCHAR(30) NOT NULL,
    item_description TEXT,
    item_effect INT DEFAULT NULL
);
-- 아이템_장신구 데이터 삽입
INSERT INTO item_accesories (item_id, item_name, item_description, item_effect) VALUES
(1, 'Ring', 'A basic ring.', 10),
(2, 'Necklace', 'A basic necklace.', 10),
(3, 'Bracelet', 'A basic bracelet.', 10);


-- 테스트 용 테이블 생성
CREATE TABLE user_test
(
    user_id    INT PRIMARY KEY,
    username   VARCHAR(32)  NOT NULL UNIQUE,
    password   VARCHAR(32) NOT NULL,
    email      VARCHAR(64) NOT NULL UNIQUE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);
-- 테스트 용 테이블 데이터 삽입
INSERT INTO user_test (user_id, username, password, email) VALUES
(1, 'user1', 'password1', 'user1@example.com'),
(2, 'user2', 'password2', 'user2@example.com'),
(3, 'user3', 'password3', 'user3@example.com'),
(4, 'user4', 'password4', 'user4@example.com'),
(5, 'user5', 'password5', 'user5@example.com'),
(6, 'user6', 'password6', 'user6@example.com'),
(7, 'user7', 'password7', 'user7@example.com'),
(8, 'user8', 'password8', 'user8@example.com');

