/**
 * @file
 * Description.
 */

(function ($) {

  Drupal.behaviors.fontawesomeIconpicker = {
    attach: function (context, settings) {
      $('.fontawesome-iconpicker-element', context).once('fontawesome-iconpicker', function(){
        $('.fontawesome-iconpicker-element', context).iconpicker();
      });
    }
  }

}(jQuery));
