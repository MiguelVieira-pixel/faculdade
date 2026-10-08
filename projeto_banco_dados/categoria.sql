use unilins;

CREATE TABLE categoria(
	cod_cat int primary key,
    descricao varchar(50)
);

SELECT * FROM produto;

ALTER TABLE produto ADD cod_cat int;
ALTER TABLE produto ADD FOREIGN KEY (cod_cat) REFERENCES categoria(cod_cat);

SELECT p.descricao, p.preco, c.descricao FROM produto p inner join categoria c on p.cod_cat=c.cod_cat
 where (c.descricao = 'material de escritorio' or c.descricao = 'Informática') and p.preco between 20 and 60;
 
 SELECT p.descricao, p.preco, c.descricao FROM produto p inner join categoria c on p.cod_cat=c.cod_cat
 where NOT c.descricao = 'Eletroeletrônico';
 
 SELECT p.cod_prod, p.descricao, p.preco, c.descricao from produto p inner join categoria c on p.cod_cat=c.cod_cat 
 order by p.preco;

SELECT c.descricao, p.descricao, p.preco from produto p inner join categoria c on p.cod_cat=c.cod_cat 
where (UPPER(c.descricao) = UPPER('informática') or UPPER(c.descricao) = UPPER('Eletroeletronico')) and p.preco between 500 and 900;

INSERT INTO categoria(cod_cat,descricao) VALUES(1, 'Informática');
INSERT INTO categoria(cod_cat,descricao) VALUES(2, 'Material de Escritório');
INSERT INTO categoria(cod_cat,descricao) VALUES(3, 'Eletroeletrônico');
INSERT INTO categoria(cod_cat,descricao) VALUES(4, 'Rede');
INSERT INTO categoria(cod_cat,descricao) VALUES(5, 'Embalagens');

INSERT INTO funcionario(cod_func,cod_depto,nome,salario)
VALUES(20, null, 'Ivan', 5000);

SELECT * FROM funcionario f left join departamento d on f.cod_depto=d.cod_depto;

UPDATE produto SET cod_cat = 1 WHERE cod_prod IN (8,9,10,11,13,14,15,16,17,20,21,22,23,30);
UPDATE produto SET cod_cat = 3 WHERE cod_prod IN (7,18,24);
UPDATE produto SET cod_cat = 4 WHERE cod_prod IN (31,32,33);
UPDATE produto SET cod_cat = 2 WHERE cod_prod IN (3,4,5,6,12,19,25,26,27,28,29);

# 1. Apresentar a descrição, preço e categoria de todos os produtos, independente da categoria a que pertença, mesmo que não pertença a nenhuma categoria.
INSERT INTO produto VALUES(67, 'Um siri fazendo barra', 3, 4.7);
UPDATE produto SET cod_cat = NULL where cod_prod = 67;
SELECT * FROM produto p left join categoria c on p.cod_cat=c.cod_cat;

# 2. Apresentar a descrição, preço e categoria de todos os produtos que possuam categoria, que custem até R$ 500,00.
SELECT p.descricao, p.preco, c.descricao FROM produto p inner join categoria c on p.cod_cat=c.cod_cat where p.preco <= 500.00;

# 3. Apresentar a descrição e o preço de todos os produtos da categoria 'Material de Escritório’.
SELECT p.descricao, p.preco, c.descricao FROM produto p inner join categoria c on p.cod_cat=c.cod_cat where c.descricao = 'Material de Escritório';

# 4. Apresentar a descrição e o preço de todos os produtos sem categoria cadastrada.
SELECT p.descricao, p.preco, c.descricao FROM produto p left join categoria c on p.cod_cat=c.cod_cat where c.cod_cat is NULL;

# 5. Apresentar as categorias sem produtos cadastrados.
SELECT p.descricao, c.descricao FROM produto p RIGHT JOIN categoria c on p.cod_cat=c.cod_cat where p.cod_cat is NULL;
