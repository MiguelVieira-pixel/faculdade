use unilins;
drop table clientes;
create table clientes(
	cod_cli INT AUTO_INCREMENT,
    nome VARCHAR(50) NOT NULL, 
    endereco VARCHAR(89) NOT NULL,
    cidade VARCHAR(1),
    telefone INT UNIQUE,
    constraint cod_cpk PRIMARY KEY (cod_cli)
    )
    
create table departamento(
	cod_depto int not null primary key,
    nome varchar(50),
    ramal varchar(10)
);

create table funcionario(
	cod_func integer not null,
	cod_depto integer,
	nome varchar(40),
	salario numeric(8,2),
	cargo varchar(90),
	data_admissao date,
	PRIMARY KEY(cod_func),
	FOREIGN KEY(cod_depto) REFERENCES departamento(cod_depto)
)

DROP TABLE departamento;

insert into departamento (cod_depto, nome, ramal) VALUES (1,'Marketing','111');
insert into departamento (cod_depto, nome, ramal) VALUES (2,'Produção','222');
insert into departamento (cod_depto, nome, ramal) VALUES (3,'Informática','333');
insert into departamento (cod_depto, nome, ramal) VALUES (4,'Vendas','444');
/*insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (7,20,'Bruno Viana',3642.6,'Gerente','2019-04-19');*/
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (1,1,'Luiz Oliveira',4500,'Gerente','2023-08-15');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (2,4,'Paulo Correia',2386.99,'Representante Comercial','2022-01-22');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (3,2,'Luiza Souza',1284.3,'Auxiliar de produção','2025-01-21');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (4,2,'Laura Andrade',1142.9,'Operador de Máquina','2024-08-05');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (5,2,'Adalberto Rodrigues',2169.82,'Supervisor de Linha','2023-07-09');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (6,2,'Maria Beatriz Ferreira',1387.85,'Abastecedor de linha deprodução','2022-09-28');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (8,1,'Julio Ribeiro',2987.41,'Administrador de marketing','2023-04-16');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (9,1,'Rafael Santana',2143.74,'Analista de marketing','2025-05-03');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (10,1,'Bianca Araújo',1623.4,'Atendente de telemarketing','2024-10-30');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (11,3,'Augusto Viana',5789.4,'Engenheiro de software','2024-11-16');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (12,3,'Barbara Lima',3841.5,'Consultor de tecnologia da informação','2023-12-17');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (13,3,'Durval Rossi',3268.4,'Analista de sistemas','2018-02-25');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (14,3,'Camila Machado',3312.8,'Analista de sistemas para internet','2017-12-04');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (15,4,'Artur Lopes',1841.2,'Consultor de vendas','2021-10-18');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (16,4,'Daniela Camargo',1547.6,'Promotor de vendas','2020-03-27');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (17,4,'Elaine Batista',1347.2,'Técnico de vendas','2025-01-16');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (18,2,'Mário Barbosa',5123.6,'Diretor','2018-01-25');
insert into funcionario (cod_func, cod_depto,nome, salario, cargo, data_admissao) values (19,2,'Mário TIME',5123.6,'Diretor','2026-01-25');

insert into clientes(nome, endereco, cidade, telefone) VALUES ('Francisco', 'Xique-Xique', 'B', 123456790);
INSERT INTO clientes (nome, endereco, cidade, telefone) VALUES 
('Maria Silva', 'Av. Paulista, 1000', 'S', 123456791),
('João Pereira', 'Rua XV de Novembro, 45', 'C', 123456792),
('Ana Costa', 'Rua Brasil, 500', 'R', 123456793),
('Carlos Souza', 'Av. Central, 200', 'B', 123456794),
('Fernanda Lima', 'Rua das Palmeiras, 88', 'P', 123456795),
('Roberto Alves', 'Rua do Comércio, 12', 'M', 123456796),
('Beatriz Rocha', 'Av. Getúlio Vargas, 305', 'G', 123456797),
('Lucas Mendes', 'Rua Sete de Setembro, 99', 'S', 123456798);
INSERT INTO clientes(nome, endereco, cidade, telefone) VALUES('Largatixq1', NULL, NULL, NULL);
ALTER TABLE clientes ADD data_nasc DATE;
UPDATE clientes set data_nasc = '2007-05-25' where cod_cli = 1;
UPDATE clientes SET data_nasc = '1995-03-10' WHERE cod_cli = 1;
UPDATE clientes SET data_nasc = '1988-11-25' WHERE cod_cli = 2;
UPDATE clientes SET data_nasc = '2001-07-04' WHERE cod_cli = 3;
UPDATE clientes SET data_nasc = '1992-01-30' WHERE cod_cli = 4;
UPDATE clientes SET data_nasc = '1985-09-18' WHERE cod_cli = 5;
UPDATE clientes SET data_nasc = '1999-12-05' WHERE cod_cli = 6;
UPDATE clientes SET data_nasc = '1990-04-12' WHERE cod_cli = 7;
UPDATE clientes SET data_nasc = '2003-08-22' WHERE cod_cli = 8;
UPDATE clientes SET data_nasc = '1997-06-15' WHERE cod_cli = 9;

alter table clientes modify column endereco VARCHAR(89);

select * from clientes where MONTH(data_nasc) = MONTH(CURDATE());
select * from clientes where telefone is not NULL and UPPER(cidade) = UPPER('B') order by nome;
delete from clientes where cidade is NULL and endereco is NULL and telefone is NULL;
select * from clientes where data_nasc < '2000-01-01';
select * from clientes where data_nasc like '2000%';
select * from clientes where nome like '%ci%';
update clientes set telefone = 1435333298 where cod_cli = 1;
select * from clientes;
ALTER TABLE clientes DROP COLUMN email;
ALTER TABLE clientes ADD email VARCHAR(100);


select * from departamento;
select * from funcionario;
select f.nome, f.salario, d.nome from funcionario f
inner join departamento d on f.cod_depto = d.cod_depto where f.salario >= 1500;

# 1. Apresentar o departamento e o ramal do funcionário 'Luiz Oliveira'.
SELECT f.nome, d.nome, d.ramal from  funcionario f inner join departamento d on f.cod_depto = d.cod_depto where f.nome = 'Luiz Oliveira';

# 2. Apresentar o nome e o departamento dos funcionário com cargo de gerente.
SELECT f.nome, d.nome, d.ramal from  funcionario f inner join departamento d on f.cod_depto = d.cod_depto where f.cargo = 'gerente';

# 3. Apresentar o nome, cargo e departamento dos funcionários admitidos a partir de 15/01/2019.
SELECT f.nome, f.cargo, d.nome, f.data_admissao from funcionario f inner join departamento d on f.cod_depto = d.cod_depto where f.data_admissao > '2019-01-15';

# 4. Apresentar o nome, cargo e departamento dos funcionários admitidos entre 2020 e 2022.
SELECT f.nome, f.cargo, d.nome, f.data_admissao from funcionario f inner join departamento d on f.cod_depto = d.cod_depto 
where f.data_admissao >= '2020-01-01' and f.data_admissao <= '2022-12-31';

# 5. Apresentar o nome, cargo e departamento dos funcionários admitidos no ano atual.
SELECT f.nome, f.cargo, d.nome, f.data_admissao from funcionario f inner join departamento d on f.cod_depto = d.cod_depto where YEAR(f.data_admissao) = YEAR(CURDATE());

# 6. Apresentar o nome, cargo e salário dos funcionários com salário acima de R$ 5.000,00.
SELECT nome, cargo, salario from funcionario where salario > 5000;

# 7. Apresentar o nome, cargo e salário dos funcionários com salário abaixo de R$ 2.000,00.
SELECT nome, cargo, salario from funcionario where salario < 2000; 

# 8. Apresentar os funcionários do departamento de ‘vendas’ ou que ocupem cargo de ‘Diretor’ e que tenham sido contratados entre 2018 e 2022.
SELECT f.nome, d.nome, f.cargo, f.data_admissao from funcionario f inner join departamento d on f.cod_depto = d.cod_depto 
where f.data_admissao >= '2018-01-01' AND f.data_admissao <= '2022-12-31' AND UPPER(d.nome) = UPPER('vendas') OR UPPER(f.cargo) = UPPER('diretor');