CREATE TABLE IF NOT EXISTS items (
    id int NOT NULL AUTO_INCREMENT,
    name varchar(255) NOT NULL,
    total_stock int NOT NULL,
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW(),
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS transactions (
    id int NOT NULL AUTO_INCREMENT,
	item_id int NOT NULL,
    item_quantity int NOT NULL,
	type varchar(3) NOT NULL,
    created_at TIMESTAMP NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMP NOT NULL DEFAULT NOW() ON UPDATE NOW(),
    PRIMARY KEY (id),
	FOREIGN KEY (item_id) REFERENCES items(id)
);

CREATE TABLE IF NOT EXISTS logs (
    id int NOT NULL AUTO_INCREMENT,
    `timestamp` timestamp NOT NULL DEFAULT NOW(),
    `method` varchar(255) NOT NULL,
    route varchar(255) NOT NULL,
    request varchar(255) NOT NULL,
    PRIMARY KEY (id)
);

delimiter //
CREATE TRIGGER tg_ai_transactions AFTER INSERT ON transactions
FOR EACH ROW
BEGIN
	UPDATE items
	SET total_stock = (SELECT sum(item_quantity) FROM transactions WHERE item_id = new.item_id)
	WHERE id = new.item_id;
END;//
