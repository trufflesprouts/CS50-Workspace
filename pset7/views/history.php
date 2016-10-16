<table class = "table table-striped">
    
    <thead>
        <tr>
            <th class="text-left">Transaction</th>
            <th class="text-left">Date/Time	</th>
            <th class="text-left">Symbol</th>
            <th class="text-left">Shares</th>
            <th class="text-left">Price</th>
        </tr>
    </thead>
    
    
    <tbody>
        <?php foreach ($positions as $position): ?>
        
        <tr>
            <td class="text-left"><?= strtoupper($position["transaction"]) ?></td>
            <td class="text-left"><?= $position["datetime"] ?></td>
            <td class="text-left"><?= strtoupper($position["symbol"]) ?></td>
            <td class="text-left"><?= number_format($position["shares"]) ?></td>
            <td class="text-left">$<?= number_format($position["price"], 2) ?></td>
        </tr>
        
        <?php endforeach ?>
    </tbody>
    
</table>