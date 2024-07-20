USE test;

-- 각 테이블의 TIMESTAMP 타입인 컬럼들은 붙은 옵션에 의해 자동으로 NOT NULL 속성이 부여됨 

-- 자식 테이블 먼저 삭제
DROP TABLE IF EXISTS user_characters;

-- 부모 테이블 삭제
DROP TABLE IF EXISTS user_accounts;

-- 나머지 테이블 삭제
DROP TABLE IF EXISTS user_test;
DROP TABLE IF EXISTS auth_key;
DROP TABLE IF EXISTS user_items;
DROP TABLE IF EXISTS item_weapons,item_armors,item_accessories;


-- 로그인 인증을 위한 key 저장 테이블
CREATE TABLE auth_key
(
    id         INT AUTO_INCREMENT PRIMARY KEY,
    key_value  VARCHAR(256) NOT NULL UNIQUE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);


-- 유저 계정 테이블 생성
CREATE TABLE user_accounts
(
    id         INT AUTO_INCREMENT PRIMARY KEY,
    user_id    VARCHAR(24)  NOT NULL UNIQUE,
    user_name  VARCHAR(50)  NOT NULL UNIQUE,
    password   VARCHAR(255) NOT NULL,
    email      VARCHAR(100) NOT NULL UNIQUE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);


-- 유저 계정 데이터 삽입은 코드로해야 됨. 왜냐하면 password를 hashing하여 저장하기 때문이다.


-- 유저 캐릭터 테이블 생성
CREATE TABLE user_characters
(
    id              INT AUTO_INCREMENT PRIMARY KEY,
    user_account_id INT         NOT NULL,
    character_name  VARCHAR(50) NOT NULL UNIQUE,
    level           INT       DEFAULT 1,
    experience      BIGINT    DEFAULT 0,
    gold            BIGINT    DEFAULT 0,
    created_at      TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at      TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    FOREIGN KEY (user_account_id) REFERENCES user_accounts (id)
);

-- 유저 캐릭터 데이터 삽입(user_accounts의 password를 hashing하여 저장하기 때문에 코드에서 생성해야 함)
# INSERT INTO user_characters (user_account_id, character_name, level, experience, gold)
# VALUES ((SELECT id FROM user_accounts WHERE user_id = 'admin'), 'admin_character', 1, 0, 500),
#        ((SELECT id FROM user_accounts WHERE user_id = 'user_1'), 'user1_character', 1, 0, 500),
#        ((SELECT id FROM user_accounts WHERE user_id = 'user_2'), 'user2_character', 1, 0, 500);


-- 유저 아이템 테이블 생성
CREATE TABLE user_items
(
    id                INT AUTO_INCREMENT PRIMARY KEY,
    user_character_id INT NOT NULL,
    item_id           INT NOT NULL,
    item_quantity     INT       DEFAULT 1,
    item_type         INT NOT NULL COMMENT 'weapon = 1, armor = 2, accesorries = 3, skin = 4 ...',
    created_at        TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at        TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    INDEX idx_user_character_id (user_character_id)
);


-- 아이템_무기 테이블 생성
CREATE TABLE item_weapons
(
    id               INT PRIMARY KEY,
    item_name        VARCHAR(30) NOT NULL,
    item_description TEXT,
    attack_power     INT DEFAULT 0,
    item_effect      INT DEFAULT NULL
);
-- 아이템_무기 데이터 삽입
INSERT INTO item_weapons (id, item_name, item_description, attack_power, item_effect)
VALUES (1, 'Sword', 'A sharp blade.', 50, NULL),
       (2, 'Dagger', 'A sharp blade.', 50, NULL),
       (3, 'Spear', 'A sharp blade.', 50, NULL);


-- 아이템_갑옷 테이블 생성
CREATE TABLE item_armors
(
    id               INT PRIMARY KEY,
    item_name        VARCHAR(30) NOT NULL,
    item_description TEXT,
    defense_power    INT DEFAULT 0,
    item_effect      INT DEFAULT NULL
);
-- 아이템_갑옷 데이터 삽입
INSERT INTO item_armors (id, item_name, item_description, defense_power, item_effect)
VALUES (1, 'fabric Armor', 'A sturdy shield.', 30, NULL),
       (2, 'Leather Armor', 'A sturdy shield.', 30, NULL),
       (3, 'Iron Armor', 'A sturdy shield.', 30, NULL);


-- 아이템_장신구 테이블 생성
CREATE TABLE item_accessories
(
    id               INT PRIMARY KEY,
    item_name        VARCHAR(30) NOT NULL,
    item_description TEXT,
    item_effect      INT DEFAULT NULL
);
-- 아이템_장신구 데이터 삽입
INSERT INTO item_accessories (id, item_name, item_description, item_effect)
VALUES (1, 'Ring', 'A basic ring.', 10),
       (2, 'Necklace', 'A basic necklace.', 10),
       (3, 'Bracelet', 'A basic bracelet.', 10);


-- 테스트 용 테이블 생성
CREATE TABLE user_test
(
    id         INT AUTO_INCREMENT PRIMARY KEY,
    username   VARCHAR(32) NOT NULL,
    password   VARCHAR(32) NOT NULL,
    email      VARCHAR(64) NOT NULL UNIQUE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);
-- 테스트 용 테이블 데이터 삽입
INSERT INTO user_test (username, password, email)
VALUES ('user1', 'password1', 'user1@example.com'),
       ('user2', 'password2', 'user2@example.com'),
       ('user3', 'password3', 'user3@example.com'),
       ('user4', 'password4', 'user4@example.com'),
       ('user5', 'password5', 'user5@example.com'),
       ('user6', 'password6', 'user6@example.com'),
       ('user7', 'password7', 'user7@example.com'),
       ('user8', 'password8', 'user8@example.com');

