<?php

    // configuration
    require("../includes/config.php"); 
    
    $rows = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
    
    $positions = [];
    foreach ($rows as $row)
    {
        $positions[] = [
            "transaction" => $row["transaction"],
            "datetime" => $row["datetime"],
            "symbol" => $row["symbol"],
            "shares" => $row["shares"],
            "price" => $row["price"]
            
        ];
    }
    
    // render portfolio
    render("history.php", ["positions" => $positions, "title" => "History"]);

?>
