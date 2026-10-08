create database vingadores;
use vingadores;

DROP TABLE IF EXISTS heroi;
DROP TABLE IF EXISTS equipe;
CREATE TABLE equipe (
cod_equipe INTEGER NOT NULL,
nome VARCHAR(50) NOT NULL,
base VARCHAR(50),
PRIMARY KEY (cod_equipe)
);
CREATE TABLE heroi (
cod_heroi INTEGER NOT NULL,
cod_equipe INTEGER,
nome VARCHAR(50) NOT NULL,
origem VARCHAR(40),
poder INTEGER,
inteligencia INTEGER,
velocidade INTEGER,
resistencia INTEGER,
PRIMARY KEY (cod_heroi),
FOREIGN KEY (cod_equipe) REFERENCES equipe(cod_equipe)
);

INSERT INTO equipe VALUES (1, 'Vingadores', 'Torre dos Vingadores');
INSERT INTO equipe VALUES (2, 'Guardiões da Galáxia', 'Benatar');
INSERT INTO equipe VALUES (3,'Wakanda', 'Wakanda');
INSERT INTO equipe VALUES (4, 'Asgard', 'Asgard');
INSERT INTO equipe VALUES (5,'Defensores', 'Nova York');
INSERT INTO equipe VALUES (6, 'X-Men', 'Instituto Xavier');



INSERT INTO heroi VALUES (1, 1, 'Homem de Ferro', 'Terra', 85, 100, 75, 75);
INSERT INTO heroi VALUES (2, 1, 'Capitão América', 'Terra', 75, 80, 70, 85);
INSERT INTO heroi VALUES (3, 1, 'Viúva Negra', 'Terra', 65, 90, 90, 75);
INSERT INTO heroi VALUES (4, 1, 'Hulk', 'Terra', 100, 65, 45, 80);
INSERT INTO heroi VALUES (5, 1, 'Gavião Arqueiro', 'Terra', 75, 80, 88, 80);
INSERT INTO heroi VALUES (6, 4, 'Thor', 'Asgard', 100, 75, 80, 95);
INSERT INTO heroi VALUES (7, 3, 'Pantera Negra', 'Terra', 90, 85, 85, 80);
INSERT INTO heroi VALUES (8, 3, 'Shuri', 'Terra', 65, 100, 75, 85);
INSERT INTO heroi VALUES (9, 2, 'Senhor das Estrelas', 'Terra', 70, 75, 80, 65);
INSERT INTO heroi VALUES (10, 2, 'Gamora', 'Zen-Whoberi', 85, 80, 90, 80);
INSERT INTO heroi VALUES (11, 2, 'Rocket', 'Halfworld', 60, 95, 88, 55);
INSERT INTO heroi VALUES (12, 2, 'Groot', 'Planeta X', 90, 55, 40, 100);
INSERT INTO heroi VALUES (13, NULL, 'Homem-Aranha', 'Terra', 85, 75, 95, 90);
INSERT INTO heroi VALUES (14, NULL, 'Doutor Estranho', 'Terra', 95, 100, 65, 70);
INSERT INTO heroi VALUES (15, NULL, 'Capitã Marvel', 'Terra', 100, 75, 100, 80);
INSERT INTO heroi VALUES (16, 1, 'Homem-Formiga', 'Terra', 70, 85, 65, 70);
INSERT INTO heroi VALUES (17, NULL, 'Vespa', 'Terra', 72, 88, 95, 75);
INSERT INTO heroi VALUES (18, 5, 'Demolidor', 'Terra', 60, 85, 88, 75);
INSERT INTO heroi VALUES (19, 4, 'Loki', 'Asgard', 88, 90, 75, 70);

-- missão 5
# Encontre um integrante dos Vingadores.
# Poder menor que 70.
# Velocidade maior ou igual a 90.
# Apresente a Energia de Combate.

SELECT
h.nome,
h.poder,
h.inteligencia,
h.resistencia,
h.poder + h.inteligencia + h.resistencia AS energia
FROM heroi h INNER JOIN equipe e on h.cod_equipe=e.cod_equipe
WHERE h.poder < 70 and velocidade >= 90 AND UPPER(e.nome) = UPPER('vingadores');



-- MISSÃO 04 | ASGARD
# Encontre um personagem pertencente à equipe cuja base seja Asgard.
# Poder igual a 100.
# Apresente personagem, equipe, atributos e Energia de Combate.

SELECT
h.nome,
h.poder,
h.inteligencia,
h.resistencia,
e.nome,
h.poder + h.inteligencia + h.resistencia AS energia
FROM heroi h INNER JOIN equipe e on h.cod_equipe=e.cod_equipe
WHERE h.poder = 100 AND UPPER(e.nome) = UPPER('asgard');

-- Missão 6 Encontre um integrante de Wakanda.
# Poder maior ou igual a 85.
# Resistência igual a 80.
# Apresente a Energia de Combate.

SELECT
h.nome,
h.poder,
h.inteligencia,
h.resistencia,
e.nome,
h.poder + h.inteligencia + h.resistencia AS energia
FROM heroi h INNER JOIN equipe e on h.cod_equipe=e.cod_equipe
WHERE h.poder >= 85 AND h.resistencia = 80 AND UPPER(e.nome) = UPPER('wakanda');

-- Missão 7

# Entre os Vingadores, encontre quem tenha poder maior ou igual a 95.
# Inteligência menor que 70.
# Resistência maior ou igual a 80.
# Apresente a Energia de Combate.

SELECT
h.nome,
h.poder,
h.inteligencia,
h.resistencia,
e.nome,
h.poder + h.inteligencia + h.resistencia AS energia
FROM heroi h INNER JOIN equipe e on h.cod_equipe=e.cod_equipe
WHERE h.poder >= 95 AND h.resistencia = 80 AND inteligencia < 70 AND UPPER(e.nome) = UPPER('vingadores');

-- Missão 8
# Encontre um personagem sem equipe cadastrada.
# Inteligência maior ou igual a 95.
# A consulta deve utilizar as duas tabelas e mostrar também a equipe.

SELECT
h.nome,
h.poder,
h.inteligencia,
h.resistencia,
e.nome,
h.poder + h.inteligencia + h.resistencia AS energia
FROM heroi h left JOIN equipe e on h.cod_equipe=e.cod_equipe
WHERE e.cod_equipe IS NULL AND inteligencia > 95;

-- Missão 9
#Entre os integrantes dos Vingadores, encontre quem tenha poder entre 70 e 80.
#3 Velocidade maior ou igual a 85.
# Apresente a Energia de Combate.

SELECT
h.nome,
h.poder,
h.inteligencia,
h.resistencia,
e.nome,
h.poder + h.inteligencia + h.resistencia AS energia
FROM heroi h left JOIN equipe e on h.cod_equipe=e.cod_equipe
WHERE poder BETWEEN 70 AND 80 AND velocidade >= 85 AND UPPER(e.nome) = UPPER('vingadores');

-- Missão 10
# Encontre um integrante de Wakanda.
# Inteligência maior ou igual a 95.
# Poder menor que 70.
# Apresente a Energia de Combate.

SELECT
h.nome,
h.poder,
h.inteligencia,
h.resistencia,
e.nome,
h.poder + h.inteligencia + h.resistencia AS energia
FROM heroi h left JOIN equipe e on h.cod_equipe=e.cod_equipe
WHERE poder < 70 AND inteligencia >= 95 AND UPPER(e.nome) = UPPER('wakanda');

-- Missão 11
#Procure entre os Guardiões da Galáxia um personagem que não tenha origem na Terra.
# Velocidade maior ou igual a 90.
# Poder maior ou igual a 80.
# Apresente a Energia de Combate.

SELECT
h.nome,
h.poder,
h.inteligencia,
h.resistencia,
e.nome,
h.poder + h.inteligencia + h.resistencia AS energia
FROM heroi h left JOIN equipe e on h.cod_equipe=e.cod_equipe
WHERE poder > 80 AND velocidade >= 90 AND UPPER(e.nome) = UPPER('Guardiões da Galáxia') AND UPPER(h.origem) <> UPPER('terra')  ;

-- Missão 12
# Encontre um personagem sem equipe cadastrada e de origem terrestre.
# Poder igual a 100.
# Velocidade igual a 100.
# A consulta deve apresentar também o nome da equipe, mesmo que não exista.

SELECT
h.nome,
h.poder,
h.inteligencia,
h.resistencia,
e.nome,
h.poder + h.inteligencia + h.resistencia AS energia
FROM heroi h left JOIN equipe e on h.cod_equipe=e.cod_equipe
WHERE poder = 100 AND velocidade = 100 AND e.cod_equipe is NULL AND UPPER(h.origem) = UPPER('terra')  ;

-- Estudo prova
#1. Apresente todos os dados dos heróis cadastrados.
SELECT * FROM heroi h;

# 2. Apresente apenas o nome, poder e inteligência de todos os heróis.
SELECT h.nome, h.poder, h.inteligencia FROM heroi h;

# 3. Apresente os heróis em ordem alfabética pelo nome.
SELECT h.nome, h.poder, h.inteligencia FROM heroi h ORDER BY h.nome;

# 4. Apresente os heróis ordenados do maior para o menor valor de poder.
SELECT h.nome, h.poder, h.inteligencia FROM heroi h ORDER BY h.poder DESC;

# 5. Apresente nome, poder e resistência dos heróis que possuam poder maior que 85.
SELECT h.nome, h.poder, h.resistencia FROM heroi h WHERE h.poder > 85;

# 6. Apresente os personagens cuja inteligência esteja entre 80 e 90.
SELECT h.nome, h.poder, h.resistencia, h.inteligencia FROM heroi h WHERE inteligencia BETWEEN 80 and 90;

#7. Apresente os personagens que tenham velocidade maior ou igual a 90 e resistência maior ou igual a 80.
SELECT h.nome, h.poder, h.resistencia, h.velocidade FROM heroi h WHERE h.velocidade >= 90 AND h.resistencia >= 80;

#8. Apresente os personagens cuja origem seja Asgard, Halfworld ou Planeta X.
SELECT h.nome, h.poder, h.origem FROM heroi h WHERE UPPER(h.origem) = UPPER('asgard') OR UPPER(h.origem) = UPPER('halfworld') OR UPPER(h.origem) = UPPER('planeta x');

#9. Apresente todos os personagens que não tenham origem na Terra.
SELECT h.nome, h.poder, h.origem FROM heroi h WHERE UPPER(h.origem) <> UPPER('terra');

#10. Apresente os personagens cujo nome comece pela letra h.
SELECT h.nome, h.poder, h.origem FROM heroi h WHERE UPPER(h.nome) LIKE UPPER('h%');

#11. Apresente os personagens cujo nome contenha a palavra Homem.
SELECT h.nome, h.poder, h.origem FROM heroi h WHERE UPPER(h.nome) LIKE UPPER('homem%');

#12. Apresente todos os personagens que estejam sem equipe cadastrada.
SELECT h.nome, h.poder, h.origem, e.nome FROM heroi h RIGHT JOIN equipe e ON h.cod_equipe = e.cod_equipe;

#13. Apresente os personagens que atendam a pelo menos uma das seguintes condições:
# poder maior ou igual a 95; ou
# inteligência maior ou igual a 95.
#Ordene do maior para o menor valor de inteligência.
SELECT h.nome, h.poder, h.inteligencia FROM heroi h WHERE h.poder >= 95 OR h.inteligencia >= 95 ORDER BY h.inteligencia DESC;

#14. Apresente os personagens que tenham:
# poder entre 70 e 90;
# inteligência maior ou igual a 80;
# resistência maior que 70.
#Ordene primeiro pelo poder e, em caso de empate, pela inteligência.

SELECT h.nome, h.poder, h.inteligencia, h.resistencia FROM heroi h WHERE h.poder BETWEEN 70 AND 90 AND h.inteligencia >= 80 AND h.resistencia > 70 
ORDER BY h.poder, h.inteligencia;

#15. Apresente nome, poder, inteligência e uma coluna chamada poder_mental, calculada por:
#poder + inteligencia
SELECT h.nome, h.poder, h.inteligencia, h.poder + h.inteligencia AS poder_mental FROM heroi h;

#16. Apresente nome e uma coluna chamada indice_combate, calculada por:
#poder + velocidade + resistencia
#Ordene do maior índice para o menor.
SELECT h.nome, h.poder + h.velocidade + h.resistencia AS indice_combate FROM heroi h ORDER BY indice_combate DESC;

#17. Imagine que todos os personagens receberão um bônus de 10 pontos no poder. Apresente:
# nome;
# poder atual;
# poder após o bônus.
#Não altere o banco. Faça o cálculo apenas no SELECT.
SELECT h.nome, h.poder, h.poder + 10 AS poder_bonus FROM heroi h;

#18. Apresente os heróis cujo resultado da expressão abaixo seja maior que 250:
#poder + inteligencia + resistencia
SELECT h.nome, h.poder, h.inteligencia, h.resistencia, h.poder + h.inteligencia + h.resistencia AS heelo FROM heroi h WHERE h.poder + h.inteligencia + h.resistencia > 250;

#19. Apresente o nome de cada personagem e o nome de sua respectiva equipe.
#Utilize INNER JOIN.
SELECT h.nome, e.nome FROM heroi h INNER JOIN equipe e ON h.cod_equipe = e.cod_equipe;

#20. Apresente nome do personagem, nome da equipe e base da equipe apenas para personagens que
#pertençam aos Vingadores.
SELECT h.nome, e.nome, e.base FROM heroi h INNER JOIN equipe e ON h.cod_equipe = e.cod_equipe WHERE UPPER(e.nome) = UPPER('vingadores');

#21. Apresente todos os personagens pertencentes aos Guardiões da Galáxia, mostrando:
# personagem;
# origem;
# equipe;
# poder.
SELECT h.nome, h.origem, e.nome, h.poder FROM heroi h INNER JOIN equipe e ON h.cod_equipe = e.cod_equipe WHERE e.cod_equipe = 2;

#22. Apresente nome, equipe e inteligência dos integrantes de Wakanda.
#Ordene do mais inteligente para o menos inteligente.
SELECT h.nome, e.nome, h.inteligencia FROM heroi h INNER JOIN equipe e ON h.cod_equipe = e.cod_equipe WHERE e.cod_equipe = 3 ORDER BY h.inteligencia DESC;

#23. Apresente os personagens que pertençam a uma equipe cuja base seja Asgard.
#Não utilize diretamente o nome da equipe no filtro.
SELECT h.nome, e.nome, h.inteligencia FROM equipe e LEFT JOIN heroi h ON e.cod_equipe = h.cod_equipe WHERE e.cod_equipe = 4;

#24. Apresente os personagens pertencentes aos Vingadores que tenham poder maior que 80.
SELECT h.nome, e.nome, h.inteligencia FROM heroi h INNER JOIN equipe e ON  h.cod_equipe = e.cod_equipe WHERE h.poder > 80 AND e.cod_equipe = 1;

#25. Apresente os integrantes dos Vingadores que tenham:
# velocidade maior ou igual a 80;
# resistência maior ou igual a 75.
SELECT h.nome, h.velocidade, h.resistencia, e.nome FROM heroi h INNER JOIN equipe e ON h.cod_equipe = e.cod_equipe 
WHERE e.cod_equipe = 1 AND h.velocidade >= 80 AND h.resistencia >= 75;

#26. Apresente todos os heróis, inclusive aqueles que não estejam vinculados a nenhuma equipe.
# nome do herói;
# nome da equipe.
SELECT h.nome, e.nome FROM heroi h RIGHT JOIN equipe e ON h.cod_equipe = e.cod_equipe;

#27. Utilizando a lógica da consulta anterior, apresente somente os personagens que estejam sem equipe.
SELECT h.nome, e.nome FROM heroi h LEFT JOIN equipe e ON h.cod_equipe = e.cod_equipe;
