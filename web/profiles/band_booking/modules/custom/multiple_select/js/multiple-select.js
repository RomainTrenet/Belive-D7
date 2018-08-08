(function($) {
	Drupal.behaviors.multiple_select = {
		attach: function (context, settings) {

		  // Avoid multiple select apply with ajax.
      $('body', context).once('multiple_select', function () {
        $('select.multiple-select').multipleSelect({
          name: '',
          placeholder: Drupal.t('Select'),
          selectAll: true,
          selectAllDelimiter: ['[', ']'],
          minimumCountSelected: 20,
          ellipsis: false,
          multiple: false,
          single: false,
          filter: true,
          width: '100%',
          animate: 'none',
          selectAllText: Drupal.t('Select all'),
          allSelected: Drupal.t('All selected'),
          countSelected: Drupal.t('# of % selected'),
          noMatchesFound: Drupal.t('No matches found'),
        });
      });
		}
	};
})(jQuery);
