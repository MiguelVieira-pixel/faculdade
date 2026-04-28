<?php
    switch($_POST['operacao']){
        case 'soma':
            echo $_POST['n1'] + $_POST['n2'];
            break;
        case 'subtracao':
            echo $_POST['n1'] - $_POST['n2'];
            break;
        case 'multiplicaccao':
            echo $_POST['n1'] * $_POST['n2'];
            break;
        case 'divisao':
            echo $_POST['n1'] / $_POST['n2'];
            break;
    }
?>