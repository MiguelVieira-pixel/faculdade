CREATE DATABASE sistema;

USE sistema;

create table usuario(
    cpf varchar(15) primary key,
    nome varchar(50),
    senha varchar(100),
    nivel int
);

create table veiculo(
    id int auto_increment primary key,
    placa varchar(10),
    modelo varchar(50),
    cpf_usuario varchar(15),
    foreing key(cpf_usuario)
    references usuario(cpf) 
);