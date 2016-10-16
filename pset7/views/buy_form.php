<form action="buy.php" method="post">
    <fieldset>
        <div class="form-group">
            <input required class="form-control" autofocus class="form-control" name="symbol" placeholder="Stock Symbol" type="txt"/>
        </div>
        <div class="form-group">
            <input required class="form-control" autofocus class="form-control" name="shares" placeholder="Number of Shares" type="number" min="0" step="1"/>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                Buy
            </button>
        </div>
    </fieldset>
</form>
