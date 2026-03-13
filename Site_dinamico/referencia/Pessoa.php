<?php
    class Pessoa {
        public $nome;
        public $sexo;

        // Método homonimo de classe não é mais construtor
        // Cosntrutor da classe (PHP só aceita um por classe)
        function __construct($wnome, $wsexo) {
            // echo "<br> No construtor de Pessoa <br>";
            $this->nome = $wnome;
            $this->sexo = $wsexo;
        }
        function __destruct() {
            // echo "<br> No destrutor de Pessoa <br>";
        }
        function display(){
            echo "<br> nome = " . $this->nome;
            echo "<br> sexo = " . $this->sexo . "<br>";
        }
    }
?>