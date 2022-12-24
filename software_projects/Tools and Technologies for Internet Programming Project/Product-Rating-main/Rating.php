<?php
class Rating{

	// variable declarations
	private $host  = '127.0.0.1';
    private $user  = 'root';
    private $password   = "";
    private $database  = "rating_db";
	private $usersTable = 'users';
	private $productTable = 'product';
    private $productRatingTable = 'product_rating';
	private $register = 'registration';
	private $dbConnect = false;
	private $settingClass = 'loginRequired'; // value can be set to 'loginRequired' or '' ,customer need to be a registered buyer to rate the product




	// default constructor method
    public function __construct(){
        if(!$this->dbConnect){
            $conn = new mysqli($this->host, $this->user, $this->password, $this->database);
            if($conn->connect_error){
                die("Error failed to connect to MySQL: " . $conn->connect_error);
            }else{
                $this->dbConnect = $conn;
            }
		}
    }

	// R - READ - SELECT * FROM PRODUCTS
	private function getData($sqlQuery) {
		$result = mysqli_query($this->dbConnect, $sqlQuery);
		if(!$result){
			die('Error in query: '. mysqli_error($this->dbConnect));
		}
		$data= array();
		while ($row = mysqli_fetch_array($result, MYSQLI_ASSOC)) {
			$data[]=$row;
		}
		return $data;
	}

	// COUNT TABLE ROWS -- SELECT COUNT(*) FROM PRODUCTS
	private function getNumRows($sqlQuery) {
		$result = mysqli_query($this->dbConnect, $sqlQuery);
		if(!$result){
			die('Error in query: '. mysqli_error($this->dbConnect));
		}
		$numRows = mysqli_num_rows($result);
		return $numRows;
	}

	// rating permission setting
	public function getSetting(){
		return  $this->settingClass;
	}

	// used for user login
	public function userLogin($username, $password){
		$sqlQuery = "
			SELECT *
			FROM ".$this->usersTable."
			WHERE username='".$username."' AND password='".$password."'";
        return  $this->getData($sqlQuery);
	}

	// used for product list
	public function getProductList(){
		$sqlQuery = "
			SELECT * FROM ".$this->productTable;
		return  $this->getData($sqlQuery);
	}

	// used for specific product by productid
	public function getProduct($product_id){
		$sqlQuery = "
			SELECT * FROM ".$this->productTable."
			WHERE id='".$product_id."'";
		return  $this->getData($sqlQuery);
	}

	// used for specific product rating by productid
	public function getProductRating($product_id){
		$sqlQuery = "
			SELECT r.id, r.product_id, r.user_id, u.username, r.rating_score, r.title, r.comment, r.reviewer,r.created_at, r.updated_at
			FROM ".$this->productRatingTable." as r
			LEFT JOIN ".$this->usersTable." as u ON (r.user_id = u.id)
			WHERE r.product_id = '".$product_id."' ORDER BY r.created_at DESC";
		return  $this->getData($sqlQuery);
	}

	// used for average product rating
	// total rating : 2+5+4 = 11
	// total count user : 3
	// rating score avg : total rating / total count user;
	public function getRatingAverage($product_id){
		$productRating = $this->getProductRating($product_id);
		$rating_score = 0;
		$count = 0;
		foreach($productRating as $productRatingDetails){
			$rating_score+= $productRatingDetails['rating_score'];
			$count += 1;
		}
		$average = 0;
		if($rating_score && $count) {
			$average = $rating_score/$count;
		}
		return $average;
	}

	// used for rating total 
	public function getRatingTotal($product_id){

	 	$sqlQuery = "
			SELECT *
			FROM ".$this->productRatingTable."  WHERE product_id = '".$product_id."'";

	  	$count = $this->getNumRows($sqlQuery);

		return $count;
	}


	// C - CREATE - insert rating information
	// used for save rating data 
	public function saveRating($POST){
		$insertRating = "INSERT INTO ".$this->productRatingTable." (product_id,  rating_score, title, comment,reviewer,email,  created_at, updated_at) VALUES ('".$POST['product_id']."',  '".$POST['rating']."', '".$POST['title']."', '".$POST['comment']."', '".$POST['reviewer']."', '".$POST['email']."', '".date("Y-m-d H:i:s")."', '".date("Y-m-d H:i:s")."')";
		mysqli_query($this->dbConnect, $insertRating);
	}


}
?>
