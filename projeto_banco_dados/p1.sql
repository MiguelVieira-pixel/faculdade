use unilins;

#1. Baseado no diagrama de classes abaixo, criar as tabelas necessárias para um Sistema de Observatório Astronômico, com as respectivas chaves primárias e estrangeiras.

create table constelacao(
	cod_costela INT AUTO_INCREMENT,
    nome_costela VARCHAR(988),
    hemisferio VARCHAR(20),
    CONSTRAINT COD_RJ PRIMARY KEY (cod_costela)
);

create table estrela(
	cod_estrela INT AUTO_INCREMENT,
    nome_estrela VARCHAR(50),
    magnitude NUMERIC(8,2),
    data_desc date,
    cod_costela INT,
    CONSTRAINT COD_CE PRIMARY KEY (cod_estrela),
    CONSTRAINT CODES_COSTELA FOREIGN KEY (cod_costela) references constelacao(cod_costela)
);

#2. Elaborar a instrução SQL para inserir as constelações:
insert into constelacao (nome_costela, hemisferio) VALUES ('Órion', 'Hemisfério Norte');
insert into constelacao (nome_costela, hemisferio) VALUES ('Cruzeiro do Sul', 'Hemisfério Sul');
INSERT INTO constelacao (nome_costela, hemisferio) VALUES ('Escorpião', 'Hemisfério Sul');
INSERT INTO constelacao (nome_costela, hemisferio) VALUES ('Lupus', 'Hemisfério Sul');
INSERT INTO constelacao (nome_costela, hemisferio) VALUES ('Ursa Maior', 'Hemisfério Norte');

#3. Cadastrar as estrelas
INSERT INTO estrela (nome_estrela, magnitude, data_desc) VALUES ('Betelgeuse', 0.42, '1890-03-20');
INSERT INTO estrela (nome_estrela, magnitude, data_desc) VALUES ('Rigel', 0.18, '1902-11-05');
INSERT INTO estrela (nome_estrela, magnitude, data_desc) VALUES ('Acrux', 0.77, '1925-01-10');
INSERT INTO estrela (nome_estrela, magnitude, data_desc) VALUES ('Antares', 1.09, '1915-07-22');
INSERT INTO estrela (nome_estrela, magnitude, data_desc) VALUES ('V462 Lupi (Nova Lupi 2025)', NULL, '2026-06-12');

#4. Criar uma consulta que apresente o nome, magnitude, data de descoberta e nome da constelação de todas as estrelas.
select e.nome_estrela, e.magnitude, e.data_desc, c.nome_costela from estrela e inner join constelacao c on e.cod_costela=c.cod_costela;

#5. Modificar a consulta para que sejam exibidos apenas as estrelas da constelação Órion.
SELECT e.nome_estrela, e.magnitude, e.data_desc, c.nome_costela from estrela e inner join constelacao c on e.cod_costela=c.cod_costela WHERE c.cod_costela = 1;

#6. Atualizar, reduzindo em 10% a magnitude de todas as estrelas do Hemisfério Sul.
UPDATE estrela e inner join constelacao c on e.cod_costela=c.cod_costela set e.magnitude = e.magnitude * 0.9 where c.hemisferio = 'Hemisfério Norte';

#7. Apresentar o nome, magnitude, data de descoberta e nome da constelação de estrelas descobertas entre 1850 e 1905, utilizando BETWEEN.
SELECT e.nome_estrela, e.magnitude, e.data_desc, c.nome_costela from estrela e inner join constelacao c on e.cod_costela=c.cod_costela 
WHERE e.data_desc BETWEEN '1850-01-01' AND '1905-12-31';

#8. Apresentar o nome, magnitude, data de descoberta e nome da constelação de estrelas descobertas no mês de novembro, utilizando a função MONTH.
SELECT e.nome_estrela, e.magnitude, e.data_desc, c.nome_costela from estrela e inner join constelacao c on e.cod_costela=c.cod_costela where MONTH(e.data_desc) = '11';

#9. Apresentar o nome, magnitude, data de descoberta e nome da constelação de estrelas que foram descobertas no ano atual.
SELECT e.nome_estrela, e.magnitude, e.data_desc, c.nome_costela from estrela e inner join constelacao c on e.cod_costela=c.cod_costela WHERE YEAR(e.data_desc) = YEAR(CURDATE());

#10. Apresentar nome da constelação, hemisfério e nome da estrela de todas as constelações, independente se há estrelas cadastradas.
SELECT c.nome_costela, c.hemisferio, e.nome_estrela from estrela e RIGHT JOIN constelacao c on e.cod_costela=c.cod_costela;