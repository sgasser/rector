<?php

namespace Rector\NetteToSymfony\Tests\Rector\MethodCall\FromHttpRequestGetHeaderToHeadersGetRector\Fixture;

use Rector\NetteToSymfony\Tests\Rector\MethodCall\FromHttpRequestGetHeaderToHeadersGetRector\Source\IrrelevantRequest;

final class SomeMissingArgumentController
{
    /**
     * @var \Rector\NetteToSymfony\Tests\Rector\MethodCall\FromHttpRequestGetHeaderToHeadersGetRector\Source\NetteHttpRequest
     */
    private $httpRequest;

    public function someAction()
    {
        $header = $this->httpRequest->getHeader('x');
    }

    public function anotherAction(IrrelevantRequest $request)
    {
        $header = $this->httpRequest->getHeader('x');
    }
}

?>
-----
<?php

namespace Rector\NetteToSymfony\Tests\Rector\MethodCall\FromHttpRequestGetHeaderToHeadersGetRector\Fixture;

use Rector\NetteToSymfony\Tests\Rector\MethodCall\FromHttpRequestGetHeaderToHeadersGetRector\Source\IrrelevantRequest;

final class SomeMissingArgumentController
{
    /**
     * @var \Rector\NetteToSymfony\Tests\Rector\MethodCall\FromHttpRequestGetHeaderToHeadersGetRector\Source\NetteHttpRequest
     */
    private $httpRequest;

    public function someAction(\Symfony\Component\HttpFoundation\Request $request)
    {
        $header = $request->headers->get('x');
    }

    public function anotherAction(IrrelevantRequest $request, \Symfony\Component\HttpFoundation\Request $symfonyRequest)
    {
        $header = $symfonyRequest->headers->get('x');
    }
}

?>
