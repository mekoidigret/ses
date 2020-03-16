<div class="container-fluid" style="height: 91.5vh;">
	<div class="row h-100">
		<div class="col-md-2 bg-dark text-light">
			<div class="container text-center" style="margin-bottom: 10px;">
				<div class="col-md-12 border-bottom" style="margin-top: 10px;">
					<?php if($photo) { ?>
						<img src="../assets/files/images/pps/<?=$photo->_name?>" class="img rounded-circle" height="100" width="100">
					<?php } else { ?>
						<img src="../assets/files/images/pps/blank.jpg" class="img rounded-circle" height="100" width="100">
					<?php } ?>
					<h5>
						<?=$_SESSION['user_username']?>
					</h5>
				</div>
			</div>
			<a class="btn btn-outline-secondary w-100 text-light text-left font-weight-bold" href="dashboard.php">
				<span>
					<img src="../assets/files/svg/dashboard.svg">
				</span>
				Dashboard
			</a>
			<a data-script="applicants" class="btn btn-outline-secondary w-100 text-light text-left font-weight-bold" href="applicants.php">
				<span>
					<img src="../assets/files/svg/people.svg">
				</span>
				Applicants
			</a>
			<a data-script="admins" class="btn btn-outline-secondary text-light w-100 text-left font-weight-bold" href="admins.php">
				<span>
					<img src="../assets/files/svg/lock.svg">
				</span>
				Administrators
			</a>
		</div>
		<div class="col-md-10" style="padding: 10px;">
			<div id="container" class="container">
				<?=$session->message()?>
			</div>
		</div>
	</div>
</div>