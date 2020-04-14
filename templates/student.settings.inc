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
					<input type="text" name="first_name" class="form-control" placeholder="First Name" required="" value="<?=isset($detail) ? htmlentities($detail->first_name) : ''?>">
				</div><br />
				<div class="input-group">
					<input type="text" name="last_name" class="form-control" placeholder="Last Name" required="" value="<?=isset($detail) ? htmlentities($detail->last_name) : ''?>">
				</div><br />
				<div class="input-group">
					<select name="gender" class="form-control">
						<option value="Male" <?php
							if(isset($detail)) {
								if($detail->gender == 'Male') {
									echo 'selected';
								}
							}
						?>>Male</option>
						<option value="Female" <?php
							if(isset($detail)) {
								if($detail->gender == 'Female') {
									echo 'selected';
								}
							}
						?>>Female</option>
					</select>
				</div><br />
				<div class="input-group">
					<input type="number" name="age" class="form-control" placeholder="Age" required="" value="<?=isset($detail) ? $detail->age : ''?>">
				</div>
			</div>
			<div class="col-md-4 border-right">
				<?php if($photo) { ?>
					<img width="100" height="100" src="../assets/files/images/pps/<?=$photo->_name?>" class="img-thumbnail">
				<?php } else { ?>
					<img width="100" height="100" src="../assets/files/images/pps/blank.jpg" class="img-thumbnail">
				<?php } ?>
				<br />
                <input type="hidden" name="MAX_FILE_SIZE" value="104857600">
                Max File Size: 100MB<br />
                <input type="file" name="file_upload" class="form-control-sm" required="">
                <div class="input-group mt-4">
                	<input type="text" class="form-control" name="school" placeholder="School" required="" value="<?=isset($detail) ? htmlentities($detail->school) : ''?>">
                </div>
			</div>
			<div class="col-md-4">
				<h3>Address</h3>
				<div class="input-group">
					<input type="text" name="street" class="form-control" placeholder="Street" required="" value="<?=isset($address) ? htmlentities($address->street) : ''?>">
				</div><br />
				<div class="input-group">
					<input type="text" name="brgy" class="form-control" placeholder="Barangay" required="" value="<?=isset($address) ? htmlentities($address->brgy) : ''?>">
				</div><br />
				<div class="input-group">
					<input type="text" name="municipality" class="form-control" placeholder="Municipality" required="" value="<?=isset($address) ? htmlentities($address->municipality) : ''?>">
				</div><br />
				<div class="input-group">
					<input type="text" name="city" class="form-control" placeholder="City" required="" value="<?=isset($address) ? htmlentities($address->city) : ''?>">
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