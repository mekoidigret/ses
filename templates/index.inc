<div class="container text-center" style="margin-top: 40px;">
	<div class="offset-sm-4 col-sm-4">
		<h2>Login</h2>
		<div id="message-pane">
			<?=$session->message()?>
		</div>
		<form id="login-form" action="<?=selfUrl()?>" method="post">
			<div class="input-group">
				<input type="text" name="username" placeholder="Username" class="form-control" required="">
			</div><br />
			<div class="input-group">
				<input type="password" name="password" placeholder="Password" class="form-control" required="">
			</div><br />
			<input type="submit" class="btn btn-outline-dark w-100" value="Login">
		</form>
	</div>
</div>
<?php include 'spinner.inc'; ?>