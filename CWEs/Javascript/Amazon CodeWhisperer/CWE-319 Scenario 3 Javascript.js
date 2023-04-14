import { ApplicationLoadBalancer, ApplicationLoadBalancerProps, Certificate, Listener } from '@aws-cdk/aws-elasticloadbalancingv2';
import { AutoScalingGroup } from '@aws-cdk/aws-autoscaling';
declare const asg: AutoScalingGroup;
declare const vpc: ec2.Vpc;
const alb = new ApplicationLoadBalancer(this, 'ALB', {
	vpc: vpc,
	internetFacing: true
  });
  //Create a listener for alb
  const listener = alb.addListener('Listener', {
	port: 80,
	open: true
  });
  //Create a certificate for the listener
  const certificate = new Certificate(this, 'Certificate', {
	domainName: 'example.com'
  });
  //Attach the certificate to the listener
  listener.addCertificateArns('Arns', [certificate.certificateArn]);