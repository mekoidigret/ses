<br />
<div class="container">
	<form id="settings-form" action="<?=selfUrl()?>" method="post" enctype="multipart/form-data" class="w-100">
		<div class="row">
			<div class="col-md-12">
				<a class="btn btn-outline-success" href="dashboard.php">
					Back
				</a>
			</div>
			<div class="col-md-12">
				<?=$session->message()?>
			</div>
			<div class="col-md-4 border-right">
				<h3>Personal Information</h3>
				<div class="input-group">
					<input type="text" name="first_name" class="form-control" placeholder="First Name" required="">
				</div><br />
				<div class="input-group">
					<input type="text" name="last_name" class="form-control" placeholder="Last Name" required="">
				</div><br />
				<div class="input-group">
					<select name="gender" class="form-control">
						<option value="Male">Male</option>
						<option value="Female">Female</option>
					</select>
				</div><br />
				<div class="input-group">
					<input type="number" name="age" class="form-control" placeholder="Age" required="">
				</div>
			</div>
			<div class="col-md-4 border-right">
				<img src="../assets/files/images/pps/blank.jpg" class="img-thumbnail">
				<br />
                <input type="hidden" name="MAX_FILE_SIZE" value="104857600">
                Max File Size: 100MB<br />
                <input type="file" name="file_upload" class="form-control-sm" required="">
			</div>
			<div class="col-md-4">
				<h3>Address</h3>
				<div class="input-group">
					<input type="text" name="street" class="form-control" placeholder="Street" required="">
				</div><br />
				<div class="input-group">
					<input type="text" name="brgy" class="form-control" placeholder="Barangay" required="">
				</div><br />
				<div class="input-group">
					<input type="text" name="municipality" class="form-control" placeholder="Municipality" required="">
				</div><br />
				<div class="input-group">
					<input type="text" name="city" class="form-control" placeholder="City" required="">
				</div>
			</div>
			<div style="margin-top: 20px;" class="col-md-12">
				<input type="submit" class="btn btn-outline-primary" value="Save Settings">
			</div>
		</div>
	</form>
</div>
<br />
<?php include 'spinner.inc'; ?>