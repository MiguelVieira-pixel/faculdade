<?php
try{$conexao = new PDO("mysql:host=localhost;dbname=sistema_veiculos", "largato", "1234");
//configura o PDO para lançar exceções em caso de erros de SQL
$conexao->setAtribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
}catch(PDOException $e){
    echo "Erro na conexão: " . $e->getMessage();
    exit;
}
?>