<?php
    require_once "Pessoa.php";
    require_once "Veiculo.php";

    class Usuario extends Pessoa {
        public $cpf;
        public $endereco;
        public $veiculos = array();

        // Método homonimo de classe não é mais construtor
        // Cosntrutor da classe (PHP só aceita um por classe)
        function __destruct() {
            // echo "<br> No destrutor de Usuario <br>";
        }

        function __display(){
            parent::display();
            echo "<br> cpf = " . $this->cpf;
            echo "<br> endereco = " . $this->endereco . "<br>";
            $this->mostraVeiculos();
        }

        function addVeiculo($v){
            array_push($this->veiculos, $v);
        }
        function mostraVeiculos() {
            echo "\n<table border>\n";
            echo "<tr style='color:red; font-family : arial; border: 1px solid black;'><th>ID</th><th>Marca</th><th>Modelo</th><th>Ano</th></tr>\n";
            $i = 0;
            while($i < count($this->veiculos)) {
                $this->veiculos[$i]->display();
                $i++;
            }
            echo "</table>\n";
        }
    }
?>