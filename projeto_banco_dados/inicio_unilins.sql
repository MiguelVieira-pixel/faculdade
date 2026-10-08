use unilins;
create table produto(
	cod_prod INT NOT NULL PRIMARY KEY,
    descricao VARCHAR(200) NOT NULL,
    estoque bit default(0),
    preco decimal(8,2)
);

INSERT INTO produto(cod_prod, descricao, preco) VALUES(1, 'Caneta', 2.5);

ALTER TABLE produto ADD validade DATE;

ALTER TABLE produto DROP COLUMN validade;

DROP TABLE produto;

CREATE TABLE depto(
	cod_depto int not null primary key,
    nome varchar(20) not null
);

CREATE TABLE empregado(
	cod int auto_increment,
    nome varchar(20) not null,
    depto int not null,
    sexo char(1) CONSTRAINT CHECK_SEXO CHECK (sexo in ('M','F')),
    idade int not null CONSTRAINT CHECK_IDADE CHECK ((idade>=18)),
    email varchar(40) not null UNIQUE, 
    ativo bit default(1),
    CONSTRAINT COD_PK PRIMARY KEY (cod),
    CONSTRAINT DEPT_FK FOREIGN KEY (depto) REFERENCES depto(cod_depto)
);
use unilins;

insert into depto(COD_DEPTO, nome)
VALUES(1, 'Financeiro');
INSERT INTO depto(cod_depto, nome)
VALUES(2, 'Secretaria');
INSERT INTO depto(cod_depto, nome)
VALUES(3, 'RH');



INSERT INTO empregado(nome, depto, sexo, idade, email) VALUES('Miguel', 4, 'F', 20, 'bitbi@gmail.com');
INSERT INTO empregado(nome, depto, sexo, idade, email) VALUES('Lucas', 2, 'M', 25, 'lucas@gmail.com');
INSERT INTO empregado(nome, depto, sexo, idade, email) VALUES('Ana', 1, 'F', 30, 'ana.silva@hotmail.com');
INSERT INTO empregado(nome, depto, sexo, idade, email) VALUES('Bruno', 3, 'M', 28, 'bruno.costa@yahoo.com');

delete from produto where cod_prod IN (1, 4, 5);
delete from produto where preco < 13;
select * from produto;


update produto set preco=preco*1.05;
update produto set preco=preco*1.1 where cod_prod=1





INSERT INTO produto(cod_prod, descricao, preco) VALUES(3,'Fone de ouvido',27.9);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(4,'Grampeador',18);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(5,'Planner semanal 60 fls',10.9);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(6,'Cola em bastão 40g',12.1);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(7,'Fragmentadora de papel',219);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(8,'Nobreak Senoidal Atrium 3000va',6331.35);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(9,'HD externo 2tb usb portátil',599.9);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(10,'Câmera webcam USB 1080p',399);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(11,'Kit wireless (teclado/mouse)',299.9);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(12,'Cadeira Gamer',1889.1);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(13,'Monitor Gamer LED 29 Ultrawide',1599.53);
INSERT INTO produto(cod_prod, descricao) VALUES(14,'Mouse Gamer usb 3200 Dpi');
INSERT INTO produto(cod_prod, descricao, preco) VALUES(15,'Impressora Multifuncional Tanque de Tinta',1259.1);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(16,'Impressora laser Monocromática',854.1);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(17,'Notebook Core i5, 8GB de Memória, 256GB SSD de Armazenamento, Tela de 15"',4084.05);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(18,'Smartphone com Android 10, 64GB de Armazenamento, Câmera de 8MP, Tela de 6,4"',1079.91);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(19,'Suporte veicular p/ Smartphone com ventosa',60);
INSERT INTO produto(cod_prod, descricao) VALUES(20,'Impressora térmica não fiscal USB / Serial');
INSERT INTO produto(cod_prod, descricao, preco) VALUES(21,'Leitor de código de barras CCD preto',171);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(22,'Mesa digitalizadora pequena',341.05);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(23,'Cartão de memória micro SD 32gb',144.4);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(24,'Drone',678.6);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(25,'Lápis de Cor 12 cores sextavado',18.1);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(26,'Pincel marca texto pastel 6 cores',22.3);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(27,'Marcador Quadro Branco 3 Cores',15.9);
INSERT INTO produto(cod_prod, descricao) VALUES(28,'Caneta Hidrográfica, 12 cores');
INSERT INTO produto(cod_prod, descricao, preco) VALUES(29,'Corretivo líquido 18ml',4.8);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(30,'Pen Drive 16gb USB 2.0',25.9);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(31,'Roteador wireless 4 portas Dual Band',379.9);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(32,'Switch 24 portas 10/100/1000 não gerenciável',749.9);
INSERT INTO produto(cod_prod, descricao, preco) VALUES(33,'Cabo de rede RJ45 CAT 5E 10m',50.2);


select * from produto where preco >= 50 and preco <= 200;
select descricao from produto where UPPER(descricao) = UPPER('Pincel marca texto pastel 6 cores');
select * from produto where descricao like '%ca%';
select * from produto where preco is not NULL;



