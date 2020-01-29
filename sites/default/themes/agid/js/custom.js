/**
 * Cityweb – CMS per siti web istituzionali dei comuni italiani
 * Copyright (C)  2016 CSI-Piemonte - C.so Unione Sovietica 216, 10134, Turin, Italy.– piattaformeweb@csi.it
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by  the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program.  If not, see http://www.gnu.org/licenses/
 */

// We define a function that takes one parameter named $.
(function ($) {

	$(".cbp-spmenu li a.preventclick").attr("href","#");
	$(".image-popup").magnificPopup({
		type:"image",
		removalDelay: 300,
		mainClass: "mfp-fade",
		gallery: {
			enabled: true, // set to true to enable gallery
		}
	});
	
	$(".region-content .block-menu-block ul.menu").addClass("grid");
	$(".region-content .block-menu-block ul.menu li").addClass("grid-sizer col-md-3 col-sm-6 col-xs-12");
	$("div#edit-basic").addClass("nav_search");
	$(".views-submit-button button.btn-info").removeClass("btn-info").addClass("btn-primary");
	
 $('.carousel_gallery').owlCarousel({
    nav: true,
    navText: ["o","b"],
    items: 3,
    dots: false,
    loop: false,
    margin: 0,
    responsive: {
      0: {
      items: 1
      },
      768: {
      items: 2
      },
      992: {
      items: 3
      }
    }
  });
	
// Here we immediately call the function with jQuery as the parameter.








$( '#contenuto-intro' ).after( '<div class="menu-detail-left"><h1>Indice della pagina</h1></div>' );

$(".field-group-html-element").each(function(){
    var idgroup = $(this).attr('id');
	var idname = $(this).find('span').first().text();
   $( '.menu-detail-left' ).append( '<a href="#' + idgroup + '">' + idname + '</a>' );
});


$(document).ready(function(){
	
	// menu amm trasparente
	$('.menu-amm-trasparente li:has(ul)').click(function(e) {
		e.preventDefault();

		if($(this).hasClass('active')) {
		  $(this).removeClass('active');
		  $(this).children('ul').slideUp();
		} else {
		  $('.menu-amm-trasparente li ul').slideUp();
		  $('.menu-amm-trasparente li').removeClass('active');
		  $(this).addClass('active');
		  $(this).children('ul').slideDown();
		}

		$('.menu-amm-trasparente li ul li a').click(function() {
		  window.location.href = $(this).attr('href');
		})
	  });
	
	
	
	// ancora per menu detaglio pagine
	
    $( ".menu-detail-left a" ).click(function( event ) {
        event.preventDefault();
        $("html, body").animate({ scrollTop: $($(this).attr("href")).offset().top }, 500);
    });
	
	// Nascondo il calendario se non ci sono eventi in home
	
	if ( $("#block-views-news-events").length ) {
	  $( "#block-views-calendario-block-1" ).show();
	  $( ".ricerca-eventi-comunali" ).show();
	} 
	else {
	 $( "#block-views-calendario-block-1" ).hide();
	 $( ".ricerca-eventi-comunali" ).hide();
	 
	}
	
	// filtri viste
	
	$( ".region-content .view-filters" ).hide();
	$( ".region-content .view-filters" ).append( "<p class='close-viewfilter'></p>" );
	$( ".open-close-filters, .close-viewfilter" ).click(function() {
	  $( ".region-content  .view-filters" ).toggle( "fast", function() {
    // Animation complete.
  });
  
});

	// link ricerca documenti

 $( "a.ancora" ).click(function( event ) {
        event.preventDefault();
        $("html, body").animate({ scrollTop: $($(this).attr("href")).offset().top }, 500);
    });
	
	
	
});	



	// Calendario home


	$( ".blocco-calendario-eventi-home .date-nav-wrapper h3 a" ).removeAttr("href");

	$( ".blocco-calendario-eventi-home td a" ).click(function( event ) {
        event.preventDefault();
		
		var date = new Date($(this)[0].href.split("/").pop());
		
		
	   $("#edit-between-date-filter-wrapper .form-text").val(((date.getDate() > 9) ? date.getDate() : ('0' + date.getDate())) + '/' + ((date.getMonth() > 8) ? (date.getMonth() + 1) : ('0' + (date.getMonth() + 1))) + '/' + date.getFullYear());
		
	   $("#views-exposed-form-news-events #edit-submit-news").click();
	   
	   
	  $('.blocco-calendario-eventi-home td.today').removeClass('today');
      $(this).parent().parent('td').addClass('today');
	   
	   
    });







}(jQuery));


