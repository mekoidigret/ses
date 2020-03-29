<div class="col-md-4">
	<br />
	<a id="back-button" class="btn btn-primary" href="admins.php">
		Back
	</a>
	<h2>Add Admin</h2>
	<p id="message-pane"></p>
	<form action="<?=selfUrl()?>" method="post">
		<div class="input-group">
			<input type="text" name="username" class="form-control" placeholder="Username" required="">
		</div><br />
		<div class="input-group">
			<input type="password" name="password" class="form-control" placeholder="Password" required="">
		</div><br />
		<input type="submit" class="btn btn-success" value="Add"><br />
	</form>
	<br />
	<?php include 'spinner.inc'; ?>
</div>
<script type="text/javascript">
	$(document).ready(() => {
		$('[action="<?=selfUrl()?>"]').submit(function(e) {
			disableLink(e);
			toggleSpinner(true);
			$.post($(this).attr('action'), $(this).serialize(), result => {
				console.log(result);
				const data = JSON.parse(result);
				toggleSpinner(false);
				if(data.status) {
					$.get('admins.php', result => {
						container.loadHTML(result);
						setTimeout(() => {
							message(data.message, 'success');
						}, 400);
					});
				}
				else {
					message(data.message, 'danger');
				}
			});
		});

		$(document).on('click', '#back-button', function(e) {
			disableLink(e);
			toggleSpinner(true);
			$.get($(this).attr('href'), result => {
				toggleSpinner(false);
				container.loadHTML(result);
			});
		});
	});
</script>