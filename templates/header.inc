<!DOCTYPE html>
<html lang="en-US">
<head>
	<?=$header->set()?>
</head>
<body>
	<nav class="navbar navbar-expand-lg navbar-dark bg-dark">
		<a id="navbar-title" class="navbar-brand" href="index.php">
			<script type="text/javascript">
				if(window.innerWidth > 400) {
					document.getElementById('navbar-title').innerHTML = <?='"'.$config['title']['full'].'"'?>;
				}
				else {
					document.getElementById('navbar-title').innerHTML = <?='"'.$config['title']['abbv'].'"'?>;
				}
			</script>
		</a>
	  	<button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbar" aria-controls="navbar" aria-expanded="false" aria-label="Toggle navigation">
	    	<span class="navbar-toggler-icon"></span>
	  	</button>
	  	<div class="collapse navbar-collapse" id="navbar">
		  	<?php if(isset($_SESSION['user_id'])) { ?>
		  		<ul class="navbar-nav mr-auto">
					<li class="nav-item <?php echo $header->title == 'Dashboard' ? 'active' : null; ?>">
						<a id="nav-items" class="nav-link" data-script="dashboard" href="dashboard.php">&nbsp; <span class="sr-only">(current)</span></a>
					</li>
		    	</ul>
		    	<ul class="navbar-nav navbar-right">
		    		<li class="nav-item dropdown">
						<a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
							<img src="../assets/files/svg/person.svg">
						</a>
						<div class="dropdown-menu dropdown-menu-right" aria-labelledby="navbarDropdown">
			          		<a class="dropdown-item <?=$header->title == 'Settings' ? 'active' : null;?>" href="settings.php">Settings</a>
			          		<div class="dropdown-divider"></div>
			          		<a class="dropdown-item" href="../logout.php">Logout</a>
			        	</div>
					</li>
		    	</ul>
		  	<?php } ?>
		</div>
	</nav>