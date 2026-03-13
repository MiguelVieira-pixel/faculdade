<?php
    class Veiculo {
        public $tipo; //1=moto, 2=automovel, 3=caminhonete
        public $marca;
        public $modelo;
        public $ano;

        // Método homonimo de classe não é mais construtor
        // Cosntrutor da classe (PHP só aceita um por classe)
        function __construct($wtipo, $wmarca, $wmodelo, $wano) {
            // echo "<br> No construtor de Veiculo <br>";
            $this->tipo = $wtipo;
            $this->marca = $wmarca;
            $this->modelo = $wmodelo;
            $this->ano = $wano;
        }

        function __destruct() {
            // echo "<br> No destrutor de Veiculo <br>";
        }

        function display() {
            echo "<tr style='color:blue; font-family : arial; border: 1px solid black;'><td>" . $this->tipo . "</td><td>" . $this->marca . "</td><td>" . $this->modelo . "</td><td>" . $this->ano . "</td></tr>\n";
        }
    }

?>