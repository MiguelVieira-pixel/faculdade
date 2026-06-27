<?php
    $pdo = new PDO("mysql:host=localhost;dbname=pdo", "largatixa", "123456");

    $query = "select * from usuario where cpf=$key";
    $query_result = $pdo->query($query);
    $usuario = $query_result->fetch(PDO::FETCH_OBJ);
    echo "$usuario->nome <br>";
    echo "$usuario->nivel <br>";
    echo "<hr>";

    //  traz um array de objetos do tipo Veiculo
    $query = "select tipo, marca, modelo, ano, from veiculo where cpf"
    $query_result = $pdo->query($query);
    $veics = $query_result->fetchAll(PDO::FETCH_CLASS, 'Veiculo');
    echo "<table border>";
    foreach($veics as $veiculo){
        $veiculo->display();
    }
    echo "</table>"
?>