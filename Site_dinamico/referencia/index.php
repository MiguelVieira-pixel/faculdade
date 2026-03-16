<?php
    require_once "Usuario.php";
    require_once "Veiculo.php";

    $us = new Usuario("Beltrano", "masculino", "5654268768", "Rua das Laranjeiras, 87");
    $us->addVeiculo(new Veiculo("1", "Honda", "XRE 190", "2019"));
    $us->addVeiculo(new Veiculo("2", "Volkswagen", "Gol", "2020"));

    $us->__display();
?>