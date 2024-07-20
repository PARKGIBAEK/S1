-- 유저 계정 데이터 삽입
INSERT INTO user_accounts (user_id, username, password, email) VALUES
('user_1', 'john_doe', 'securepassword1', 'john@example.com'),
('user_2', 'jane_doe', 'securepassword2', 'jane@example.com');

-- 유저 캐릭터 데이터 삽입
INSERT INTO user_characters (user_id, character_name, level, experience, gold) VALUES
(1, 'JohnTheWarrior', 10, 1500, 500),
(2, 'JaneTheMage', 8, 1200, 300);

-- 아이템_무기 데이터 삽입
INSERT INTO item_weapons (item_id, item_name, item_description, attack_power, item_effect) VALUES
(1, 'Sword', 'A sharp blade.', 50, NULL);

-- 아이템_갑옷 데이터 삽입
INSERT INTO item_armors (item_id, item_name, item_description, defense_power, item_effect) VALUES
(2, 'Shield', 'A sturdy shield.', 30, NULL);

-- 아이템_장신구 데이터 삽입
INSERT INTO item_accesories (item_id, item_name, item_description, item_effect) VALUES
(3, 'Ring', 'A magical ring.', 10);

-- 유저 아이템 데이터 삽입
INSERT INTO user_items (profile_id, item_id, item_quantity, item_type) VALUES
(1, 1, 1, 1), -- JohnTheWarrior가 Sword를 소유
(2, 2, 1, 2), -- JaneTheMage가 Shield를 소유
(2, 3, 1, 3); -- JaneTheMage가 Ring를 소유

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
