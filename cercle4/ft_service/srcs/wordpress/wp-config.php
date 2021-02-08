<?php

define( 'DB_NAME', 'wordpress' );

define( 'DB_USER', 'admin' );

define( 'DB_PASSWORD', 'password' );

define( 'DB_HOST', 'mysql' );

define( 'DB_CHARSET', 'utf8' );

define( 'DB_COLLATE', '' );

define( 'CONCATENATE_SCRIPTS', false );

define( 'SCRIPT_DEBUG', true );

 define('AUTH_KEY',         'jIKOz@j{dy~YnkwpmLMj_|7h3V:5&A>OO-iF:5}p0k)c}0!@LmHT-wr^A+?-(Mhk');
 define('SECURE_AUTH_KEY',  '?y8#,,Vp; 8Jptwix3yNte4z?1&l+[ vpa_!$RhU!iw@Bk~d{)a{/nq:gOcO;!A$');
 define('LOGGED_IN_KEY',    'G&aw0PR0Iw>o*A+{lAGO 4e{2cj1U.5UUfPJH^u`Qe-H3A,wBka8^/h [Z#5|n5l');
 define('NONCE_KEY',        'Z@Z4=L_t+z|ltHV9GX^k]ASGlBy-d8z/.Y{N;6.}vRi:43l%#q-%Lq:- vgY3|E8');
 define('AUTH_SALT',        '#6`LwI9,lZK&~Zf}rkVN$+<jvk><^?|9 PGaTU+.3D>32zPoqKErDz Gl@u;{pp-');
 define('SECURE_AUTH_SALT', ' t8=7<jMTag:%8_F~XJ?7ITOaQD&0FJGdY?GFwHNCn r#np=$>D+HAobLV5Vslm6');
 define('LOGGED_IN_SALT',   ' :&JMq?olihp[5bLn2:lpq!@+mGTOFI%wir}7JvV|:0l@gSaIq?zD TFxik.P}Qi');
 define('NONCE_SALT',       'a-.lE-&Mymjf.C])I%N.WMEw@Db%M{^)E@[Z!E^FM20{o)bai,EcI4G_K~@>+3`v');


$table_prefix = 'wp_';

define( 'WP_DEBUG', false );

if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

require_once( ABSPATH . 'wp-settings.php' );