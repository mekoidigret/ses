<div class="col-md-4">
	<br />
	<a id="back-button" class="btn btn-primary" href="applicants.php">
		Back
	</a>
	<h2>Add Student</h2>
	<p id="message-pane"></p>
	<form action="<?=selfUrl()?>" method="post">
		<div class="input-group">
			<input type="text" name="full_name" class="form-control" placeholder="Full Name" required="">
		</div><br />
		<div class="input-group">
			<select name="gender" class="form-control">
				<option value="Male">Male</option>
				<option value="Female">Female</option>
			</select>
		</div><br />
		<div class="input-group">
			<select name="status" class="form-control">
				<option value="Enrolled">Enrolled</option>
				<option value="Dropped">Dropped</option>
			</select>
		</div><br />
		<div class="input-group">
			<input type="text" name="school" class="form-control" placeholder="School Name" required="">
		</div><br />
		<div class="input-group">
			<select name="year" class="form-control">
				<?php for($i = 2015; $i <= 2020; $i++) { ?>
					<option value="<?=$i?>"><?=$i?></option>
				<?php } ?>
			</select>
		</div><br />
		<input type="submit" class="btn btn-success" value="Add"><br />
	</form>
	<br />
	<?php include 'spinner.inc'; ?>
</div>
<script defer="" type="text/javascript">
	$(document).ready(() => {
		$('[action="<?=selfUrl()?>"]').submit(function(e) {
			disableLink(e);
			toggleSpinner(true);
			$.post($(this).attr('action'), $(this).serialize(), data => {
				if(data.status) {
					message(data.message, 'success');
					$('input[name="school"]').val('');
					$('input[name="full_name"]').val('');
				}
				else {
					message(data.message, 'danger');
				}
				toggleSpinner(false);
			}, 'json');
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