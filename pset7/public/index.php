<?php

    // configuration
    require("../includes/config.php"); 
    
    $rows = CS50::query("SELECT symbol, shares FROM portfolio WHERE user_id = ?", $_SESSION["id"]);
    
    $cashier = CS50::query("SELECT cash FROM users where id = ?", $_SESSION["id"]);
    $cash = $cashier[0]["cash"];

    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
            ];
        }
        else
        {
            apologize("A Terrible Thing Happened");
        }
    }
    
    $shares_worth = 0;
    foreach ($positions as $position)
    {
        $shares_worth = $shares_worth + ($position["shares"] * $position["price"]);
    }
    
    // render portfolio
    render("portfolio.php", ["cash" => $cash, "shares_worth" => $shares_worth, "positions" => $positions, "title" => "Portfolio"]);

?>
